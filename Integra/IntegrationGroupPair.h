#pragma once

#include "ODBCclass.h"

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
		property List<array<String^>^>^ AttributesDataDgv
		{
			List<array<String^>^>^ get()
			{
				return _dgvAttrs;
			}
			void set(List<array<String^>^>^ value)
			{
				_dgvAttrs = value;
			}
		}

	private:
		OdbcClass^ _odbc;

		String^ _name;
		String^ _sourceGroupId;
		String^ _sourceGroupName;
		String^ _targetGroupId;
		String^ _targetGroupName;

		Object^ _sourceNamesDataSource;
		Object^ _targetNamesDataSource;
		List<array<String^>^>^ _dgvAttrs;

	public:

		IntegrationGroupPair(String^ name, String^ sourceGroupId, String^ sourceGroupName, String^ targetGroupId, String^ targetGroupName)
		{
			_name = name;
			_sourceGroupId = sourceGroupId;
			_sourceGroupName = sourceGroupName;
			_targetGroupId = targetGroupId;
			_targetGroupName = targetGroupName;
		}




	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~IntegrationGroupPair() 
		{

		}


	};
}