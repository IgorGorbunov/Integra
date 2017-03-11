#pragma once

#include "ODBCclass.h"
#include "ComplexAttribute.h"


namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс 
	/// </summary>
	public ref class IntegrationGroupPair 
	{
	public:
		property int Id
		{
			int get()
			{
				return _id;
			}
		}	
		property String^ Name
		{
			String^ get()
			{
				return _name;
			}
		}

		property String^ SourceGroupId
		{
			String^ get()
			{
				return _sourceGroupId;
			}
		}
		property String^ SourceGroupName
		{
			String^ get()
			{
				return _sourceGroupName;
			}
		}
		property String^ TargetGroupId
		{
			String^ get()
			{
				return _targetGroupId;
			}
		}
		property String^ TargetGroupName
		{
			String^ get()
			{
				return _targetGroupName;
			}
		}
		property String^ FullName
		{
			String^ get()
			{
				return String::Format("{0} ({1}({2}) - {3}({4}))", 
					Name, SourceGroupName, SourceGroupId, TargetGroupName, TargetGroupId);
			}
		}

		property Object^ SourceNamesDataSource
		{
			Object^ get()
			{
				return _sourceNamesDataSource;
			}
			void set(Object^ value)
			{
				_sourceNamesDataSource = value;
			}
		}
		property Object^ TargetNamesDataSource
		{
			Object^ get()
			{
				return _targetNamesDataSource;
			}
			void set(Object^ value)
			{
				_targetNamesDataSource = value;
			}
		}
		property List<array<Object^>^>^ AttributesDataDgv
		{
			List<array<Object^>^>^ get()
			{
				return _dgvAttrs;
			}
			void set(List<array<Object^>^>^ value)
			{
				_dgvAttrs = value;
			}
		}

		property List<Attribute^>^ SourceGroupingAttrs
		{
			List<Attribute^>^ get()
			{
				return _sourceGroupingAttrs;
			}
			void set(List<Attribute^>^ sourceGroupingAttrs)
			{
				_sourceGroupingAttrs = sourceGroupingAttrs;
			}
		}
		property List<Attribute^>^ TargetGroupingAttrs
		{
			List<Attribute^>^ get()
			{
				return _targetGroupingAttrs;
			}
			void set(List<Attribute^>^ targetGroupingAttrs)
			{
				_targetGroupingAttrs = targetGroupingAttrs;
			}
		}
		property List<ComplexAttribute^>^ ComplexAttrs
		{
			List<ComplexAttribute^>^ get()
			{
				return _complexAttrs;
			}
			void set(List<ComplexAttribute^>^ complexAttrs)
			{
				_complexAttrs = gcnew List<ComplexAttribute ^>(complexAttrs);
			}
		}

		property Dictionary<Attribute^, Attribute^>^ SimpleAttrs
		{
			Dictionary<Attribute^, Attribute^>^ get()
			{
				if (!_attrsIsSet)
				{
					SetAttrs();
				}
				return _simpleAttrs;
			}
		}
		property Dictionary<Attribute^, Attribute^>^ EquivAttrs
		{
			Dictionary<Attribute^, Attribute^>^ get()
			{
				if (!_attrsIsSet)
				{
					SetAttrs();
				}
				return _equivAttrs;
			}
		}

	private:
		OdbcClass^ _odbc;
		int _id;

		String^ _name;
		String^ _sourceGroupId;
		String^ _sourceGroupName;
		String^ _targetGroupId;
		String^ _targetGroupName;

		Object^ _sourceNamesDataSource;
		Object^ _targetNamesDataSource;
		List<array<Object^>^>^ _dgvAttrs;
		List<ComplexAttribute^>^ _complexAttrs;

		List<Attribute^>^ _sourceGroupingAttrs;
		List<Attribute^>^ _targetGroupingAttrs;

		bool _attrsIsSet;
		Dictionary<Attribute^, Attribute^>^ _simpleAttrs;
		Dictionary<Attribute^, Attribute^>^ _equivAttrs;

		

	public:

		static List<IntegrationGroupPair^>^ GetGroups(OdbcClass^ odbc, int integrationParamId)
		{
			List<IntegrationGroupPair^>^ list;
			String^ squery = "select DG.ID, DG.NAME_GR, DG.IDS, DG.IDT from {0}DB_GROUPS DG where DG.ID_INTGR_PARAMS = {1} order by DG.ID";
			squery = String::Format(squery, odbc->schema, integrationParamId);

			List<Object^>^ resList = odbc->ExecuteQuery(squery);
			if (resList != nullptr && resList->Count > 0)
			{
				list = gcnew List<IntegrationGroupPair ^>();
				for (int i = 0; i < resList->Count; i+=4)
				{
					int id = odbc->GetResInt(resList[i+0]);
					String^ name = resList[i+1]->ToString();
					String^ idS = resList[i+2]->ToString();
					String^ idT = resList[i+3]->ToString();

					IntegrationGroupPair^ groupPair = gcnew IntegrationGroupPair(id, name, idS, idT);
					list->Add(groupPair);
				}
			}

			return list;
		}

		IntegrationGroupPair(int id, String^ name, String^ sourceGroupId, String^ targetGroupId)
		{
			_id = id;
			_name = name;
			_sourceGroupId = sourceGroupId;
			_targetGroupId = targetGroupId;

			_attrsIsSet = false;
		}

		IntegrationGroupPair(String^ name, String^ sourceGroupId, String^ sourceGroupName, String^ targetGroupId, String^ targetGroupName)
		{
			_name = name;
			_sourceGroupId = sourceGroupId;
			_sourceGroupName = sourceGroupName;
			_targetGroupId = targetGroupId;
			_targetGroupName = targetGroupName;
			_attrsIsSet = false;
		}

		void InsertToDb(OdbcClass^ odbc, int intgrParamsId)
		{
			_odbc = odbc;
			InsertGroup(intgrParamsId);
		}

		

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~IntegrationGroupPair() 
		{

		}

		private:
			void InsertGroup(int intgrParamsId)
			{
				String^ columns = "ID,ID_INTGR_PARAMS,NAME_GR,CREATE_USER,CREATE_DATE,IDS,IDT";
				String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
				String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);

				String^ sName = OdbcClass::GetSqlString(Name);
				String^ sGroupId = OdbcClass::GetSqlString(SourceGroupId);
				String^ tGroupId = OdbcClass::GetSqlString(TargetGroupId);

				_id = _odbc->GetLastFreeId(_odbc->schema + "DB_GROUPS");

				String^ sQuery = String::Format("insert into {0}DB_GROUPS ({1}) values ({2}, {3}, {4}, {5}, {6}, {7}, {8})",
					_odbc->schema, columns, _id, intgrParamsId, sName, sqlUser, sqlDate, sGroupId, tGroupId);
				_odbc->ExecuteNonQuery(sQuery);
			}

			void SetAttrs()
			{
				_simpleAttrs = gcnew Dictionary<Attribute ^, Attribute ^>();
				_equivAttrs = gcnew Dictionary<Attribute ^, Attribute ^>();
				for each (array<Object^>^ row in _dgvAttrs)
				{
					String^ sourceAttrName = row[1]->ToString();
					Attribute^ sourceAttr = GetAttr(sourceAttrName, SourceGroupingAttrs);
					String^ targetAttrName = row[5]->ToString();
					Attribute^ targetAttr = GetAttr(targetAttrName, TargetGroupingAttrs);

					if (row[0] == nullptr || (bool)row[0] == false)
					{
						_simpleAttrs->Add(sourceAttr, targetAttr);
					}
					else
					{
						_equivAttrs->Add(sourceAttr, targetAttr);
					}
				}
				_attrsIsSet = true;
			}

			Attribute^ GetAttr(String^ attrName, List<Attribute^>^ attrList)
			{
				for each (Attribute^ attr in attrList)
				{
					if (attr->GroupAttrCodeValue == attrName || attr->GroupAttrNameValue == attrName)
					{
						return attr;
					}
				}
				return nullptr;
			}

			
	};
}