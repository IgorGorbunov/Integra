#pragma once

#include "Logger.h"
#include "BookSettings.h"
#include "Position.h"
#include "IntegrationSettings.h"
#include "IntegrationResult.h"


namespace Integra {

	using namespace System::Collections::Generic;

	/// <summary>
	/// ����� spravochnika Semantic
	/// </summary>
	public ref class Book abstract
	{

	protected:
		BookSettings^ BookSetting;
		IntegrationSettings^ _intSettings;
		OdbcClass^ _odbc;

		Attribute^ _attrId;

	public:
		Book(BookSettings^ bookSettings, IntegrationSettings^ intSettings, OdbcClass^ odbc) 
		{
			_odbc = odbc;
			BookSetting = bookSettings;
			_intSettings = intSettings;
			_attrId = BookSetting->AttrId;
		}



	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Book() 
		{

		}


	public:
		virtual Dictionary<String^, String^>^ GetAllGroupNames() abstract;
		virtual Object^ GetGroupAttrValue(Attribute^ attribute, String^ idGroup) abstract;
		virtual Object^ GetPosAttrValue(Attribute^ attribute, String^ idPos) abstract;

		virtual List<Position^>^ GetAllPositions() abstract;
		virtual List<Position^>^ GetAllPositionsTable(List<Attribute^>^ attrs, List<Object^>^ filters, List<Object^>^ links) abstract;
		virtual List<Position^>^ GetGroupPositionsTable(Attribute^ groupAttr, String^ dbGroupId, String^ groupFullTable, List<Attribute^>^ attrs, List<Object^>^ filters, List<Object^>^ links) abstract;

		virtual List<Position^>^ GetAllPositions2(System::ComponentModel::BackgroundWorker^ worker, System::ComponentModel::DoWorkEventArgs ^ e) abstract;
		virtual List<Position^>^ GetAllPositions22(int% n) abstract;

		virtual void AddPosition(Dictionary<Attribute^, String^>^ attrsAndNewVals, Object^ idVal, Object^ titleVal, IntegrationResult^ result, int isTarget) abstract;
		virtual void UpdatePosition(Position^ currentPos, Dictionary<Attribute^, String^>^ attrsAndNewVals) abstract;
		virtual void UpdatePositionForEachAttr(Position^ currentPos, Dictionary<Attribute^, String^>^ attrsAndNewVals, IntegrationResult^ result, int isTarget) abstract;

		virtual void Remove(String^ posId) abstract;

		virtual Object^ GetSemObject(String^ location) abstract;

	protected:

		List<Object^>^ GetSourceTitle()
		{
			return _odbc->ExecuteQuery("select distinct FULL_CODE from " + _odbc->schema + "INTEGRATION_ATTRIBUTES where ID in (select ID_SOURCE_ATTRIBUTE from " + _odbc->schema + "ATTRIBUTE_PAIRS where ID_PARAMETRS = " + _intSettings->Id + ")");
		}

		List<Object^>^ GetTargetTitle()
		{
			return _odbc->ExecuteQuery("select distinct FULL_CODE from " + _odbc->schema + "INTEGRATION_ATTRIBUTES where ID in (select ID_TARGET_ATTRIBUTE from " + _odbc->schema + "ATTRIBUTE_PAIRS where ID_PARAMETRS = " + _intSettings->Id + ")");
		}
	};
}