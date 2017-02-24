#pragma once

#include "ODBCclass.h"
#include "Attribute.h"
#include "ComplexAttribute.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс 
	/// </summary>
	public ref class AttributePair 
	{
	public:


	private:
		OdbcClass^ _odbc;

		int _id;
		Attribute^ _attr1;
		Attribute^ _attr2;
		ComplexAttribute^ _cAttr1;
		ComplexAttribute^ _cAttr2;

	public:

		AttributePair(OdbcClass^ odbc, int id, Attribute^ attr1, Attribute^ attr2, ComplexAttribute^ cAttr1, ComplexAttribute^ cAttr2)
		{
			_odbc = odbc;
			_id = id;
			_attr1 = attr1;
			_attr2 = attr2;
			_cAttr1 = cAttr1;
			_cAttr2 = cAttr2;
		}

		static List<AttributePair^>^ GetLinks(int integrationSchemaId, OdbcClass^ odbc)
		{
			List<AttributePair^>^ list;
			String^ squery = "select APP.ID, " +
				"(select IAA1.ID from {0}INTEGRATION_ATTRIBUTES IAA1 where IAA1.ID = APP.ID_SOURCE_ATTRIBUTE)," +
				"(select IAA2.NAME from {0}INTEGRATION_ATTRIBUTES IAA2 where IAA2.ID = APP.ID_SOURCE_ATTRIBUTE)," +
				"(select IAA3.SCHEMA_NAME from {0}INTEGRATION_ATTRIBUTES IAA3 where IAA3.ID = APP.ID_SOURCE_ATTRIBUTE)," +
				"(select IAA4.TABLE_NAME from {0}INTEGRATION_ATTRIBUTES IAA4 where IAA4.ID = APP.ID_SOURCE_ATTRIBUTE)," +
				"(select IAA5.ATTR_NAME from {0}INTEGRATION_ATTRIBUTES IAA5 where IAA5.ID = APP.ID_SOURCE_ATTRIBUTE)," +
				"(select IAA6.ID_INTGR_BOOK from {0}INTEGRATION_ATTRIBUTES IAA6 where IAA6.ID = APP.ID_SOURCE_ATTRIBUTE), " +
				"(select IAA7.DATA_TYPE from {0}INTEGRATION_ATTRIBUTES IAA7 where IAA7.ID = APP.ID_SOURCE_ATTRIBUTE)," +
				"(select IAA8.MAX_LENGTH from {0}INTEGRATION_ATTRIBUTES IAA8 where IAA8.ID = APP.ID_SOURCE_ATTRIBUTE)," +
				"(select IAA9.ID from {0}INTEGRATION_ATTRIBUTES IAA9 where IAA9.ID = APP.ID_TARGET_ATTRIBUTE)," +
				"(select IAA10.NAME from {0}INTEGRATION_ATTRIBUTES IAA10 where IAA10.ID = APP.ID_TARGET_ATTRIBUTE)," +
				"(select IAA11.SCHEMA_NAME from {0}INTEGRATION_ATTRIBUTES IAA11 where IAA11.ID = APP.ID_TARGET_ATTRIBUTE)," +
				"(select IAA12.TABLE_NAME from {0}INTEGRATION_ATTRIBUTES IAA12 where IAA12.ID = APP.ID_TARGET_ATTRIBUTE)," +
				"(select IAA13.ATTR_NAME from {0}INTEGRATION_ATTRIBUTES IAA13 where IAA13.ID = APP.ID_TARGET_ATTRIBUTE)," +
				"(select IAA14.ID_INTGR_BOOK from {0}INTEGRATION_ATTRIBUTES IAA14 where IAA14.ID = APP.ID_TARGET_ATTRIBUTE)," +
				"(select IAA15.DATA_TYPE from {0}INTEGRATION_ATTRIBUTES IAA15 where IAA15.ID = APP.ID_TARGET_ATTRIBUTE)," +
				"(select IAA16.MAX_LENGTH from {0}INTEGRATION_ATTRIBUTES IAA16 where IAA16.ID = APP.ID_TARGET_ATTRIBUTE)," +
				"(select CAA1.ID from {0}COMPLEX_ATTRS CAA1 where CAA1.ID = APP.ID_SOURCE_COMPLEX_ATTR), " +
				"(select CAA2.NAME_ATTR from {0}COMPLEX_ATTRS CAA2 where CAA2.ID = APP.ID_SOURCE_COMPLEX_ATTR), " +
				"(select CAA3.COMPLEX_TYPE from {0}COMPLEX_ATTRS CAA3 where CAA3.ID = APP.ID_SOURCE_COMPLEX_ATTR), " +
				"(select CAA4.START_COMPOSE_ATTR_ID from {0}COMPLEX_ATTRS CAA4 where CAA4.ID = APP.ID_SOURCE_COMPLEX_ATTR), " +
				"(select CAA5.SELECT_TYPE from {0}COMPLEX_ATTRS CAA5 where CAA5.ID = APP.ID_SOURCE_COMPLEX_ATTR), " +
				"(select CAA6.FIRST_SYMBOL_NUM from {0}COMPLEX_ATTRS CAA6 where CAA6.ID = APP.ID_SOURCE_COMPLEX_ATTR), " +
				"(select CAA7.SYMBOL_COUNT from {0}COMPLEX_ATTRS CAA7 where CAA7.ID = APP.ID_SOURCE_COMPLEX_ATTR), " +
				"(select CAA8.SPLIT_SYMBOLS from {0}COMPLEX_ATTRS CAA8 where CAA8.ID = APP.ID_SOURCE_COMPLEX_ATTR), " +
				"(select CAA9.USE_PART from {0}COMPLEX_ATTRS CAA9 where CAA9.ID = APP.ID_SOURCE_COMPLEX_ATTR), " +
				"(select CAA10.SELECT_ATTR_ID from {0}COMPLEX_ATTRS CAA10 where CAA10.ID = APP.ID_SOURCE_COMPLEX_ATTR), " +
				"(select CAA11.ID from {0}COMPLEX_ATTRS CAA11 where CAA11.ID = APP.ID_TARGET_COMPLEX_ATTR), " +
				"(select CAA12.NAME_ATTR from {0}COMPLEX_ATTRS CAA12 where CAA12.ID = APP.ID_TARGET_COMPLEX_ATTR), " +
				"(select CAA13.COMPLEX_TYPE from {0}COMPLEX_ATTRS CAA13 where CAA13.ID = APP.ID_TARGET_COMPLEX_ATTR), " +
				"(select CAA14.START_COMPOSE_ATTR_ID from {0}COMPLEX_ATTRS CAA14 where CAA14.ID = APP.ID_TARGET_COMPLEX_ATTR), " +
				"(select CAA15.SELECT_TYPE from {0}COMPLEX_ATTRS CAA15 where CAA15.ID = APP.ID_TARGET_COMPLEX_ATTR), " +
				"(select CAA16.FIRST_SYMBOL_NUM from {0}COMPLEX_ATTRS CAA16 where CAA16.ID = APP.ID_TARGET_COMPLEX_ATTR), " +
				"(select CAA17.SYMBOL_COUNT from {0}COMPLEX_ATTRS CAA17 where CAA17.ID = APP.ID_TARGET_COMPLEX_ATTR), " +
				"(select CAA18.SPLIT_SYMBOLS from {0}COMPLEX_ATTRS CAA18 where CAA18.ID = APP.ID_TARGET_COMPLEX_ATTR), " +
				"(select CAA19.USE_PART from {0}COMPLEX_ATTRS CAA19 where CAA19.ID = APP.ID_TARGET_COMPLEX_ATTR), " +
				"(select CAA20.SELECT_ATTR_ID from {0}COMPLEX_ATTRS CAA20 where CAA20.ID = APP.ID_TARGET_COMPLEX_ATTR) " +
				"from {0}ATTRIBUTE_PAIRS APP where APP.ID_PARAMETRS = {1}";


			squery = String::Format(squery, odbc->schema, integrationSchemaId);

			List<Object^>^ resList = odbc->ExecuteQuery(squery);
			if (resList != nullptr && resList->Count > 0)
			{
				list = gcnew List<AttributePair ^>();
				for (int i = 0; i < resList->Count; i+=37)
				{
					int parametrsId = odbc->GetResInt(resList[i+0]);
					Attribute^ attr1;
					Attribute^ attr2;
					ComplexAttribute^ cAttr1;
					ComplexAttribute^ cAttr2;
					
					int attrId1 = odbc->GetResInt(resList[i+1]);
					if (attrId1 != -1)
					{
						String^ attrName1 = OdbcClass::GetResString(resList[i+2]);
						String^ attrSchemaName1 = OdbcClass::GetResString(resList[i+3]);
						String^ attrTableName1 = OdbcClass::GetResString(resList[i+4]);
						String^ attrCode1 = OdbcClass::GetResString(resList[i+5]);
						int attrIntBookId1 = odbc->GetResInt(resList[i+6]);
						String^ attrDataType1 = OdbcClass::GetResString(resList[i+7]);
						int attrMaxLength1 = odbc->GetResInt(resList[i+8]);
						attr1 = gcnew Attribute(attrId1, attrName1, attrSchemaName1, attrTableName1, attrCode1, attrIntBookId1, attrDataType1, attrMaxLength1 + "", odbc);
					}
					int attrId2 = odbc->GetResInt(resList[i+9]);
					if (attrId2 != -1)
					{
						String^ attrName1 = OdbcClass::GetResString(resList[i+10]);
						String^ attrSchemaName1 = OdbcClass::GetResString(resList[i+11]);
						String^ attrTableName1 = OdbcClass::GetResString(resList[i+12]);
						String^ attrCode1 = OdbcClass::GetResString(resList[i+13]);
						int attrIntBookId1 = odbc->GetResInt(resList[i+14]);
						String^ attrDataType1 = OdbcClass::GetResString(resList[i+15]);
						int attrMaxLength1 = odbc->GetResInt(resList[i+16]);
						attr2 = gcnew Attribute(attrId2, attrName1, attrSchemaName1, attrTableName1, attrCode1, attrIntBookId1, attrDataType1, attrMaxLength1 + "", odbc);
					}
					int complexAttrId1 = odbc->GetResInt(resList[i+17]);
					if (complexAttrId1 != -1)
					{
						String^ attrName = OdbcClass::GetResString(resList[i+18]);
						int complexType = odbc->GetResInt(resList[i+19]);
						if (complexType == 0)
						{
							int startComposeId = odbc->GetResInt(resList[i+20]);
							if (attr1 == nullptr)
							{
								cAttr1 = gcnew ComplexAttribute(odbc, attr2, attrName, false, startComposeId);
							}
							else
							{
								cAttr1 = gcnew ComplexAttribute(odbc, attr1, attrName, true, startComposeId);
							}
						}
						else
						{
							int selectType = odbc->GetResInt(resList[i+21]);
							int selectAttrId = odbc->GetResInt(resList[i+26]);
							if (selectType == 0)
							{
								int iFirstSymbol = odbc->GetResInt(resList[i+22]);
								int nSymbols = odbc->GetResInt(resList[i+23]);
								if (attr1 == nullptr)
								{
									cAttr1 = gcnew ComplexAttribute(odbc, attr2, attrName, false, selectAttrId, iFirstSymbol, nSymbols);
								}
								else
								{
									cAttr1 = gcnew ComplexAttribute(odbc, attr1, attrName, true, selectAttrId, iFirstSymbol, nSymbols);
								}
							}
							else
							{
								String^ splitSymbols = OdbcClass::GetResString(resList[i+24]);
								int usePart = odbc->GetResInt(resList[i+25]);
								if (attr1 == nullptr)
								{
									cAttr1 = gcnew ComplexAttribute(odbc, attr2, attrName, false, selectAttrId, splitSymbols, usePart);
								}
								else
								{
									cAttr1 = gcnew ComplexAttribute(odbc, attr1, attrName, true, selectAttrId, splitSymbols, usePart);
								}
							}
							
						}
					}

					int complexAttrId2 = odbc->GetResInt(resList[i+27]);
					if (complexAttrId2 != -1)
					{
						String^ attrName = OdbcClass::GetResString(resList[i+28]);
						int complexType = odbc->GetResInt(resList[i+29]);
						if (complexType == 0)
						{
							int startComposeId = odbc->GetResInt(resList[i+30]);
							if (attr1 == nullptr)
							{
								cAttr2 = gcnew ComplexAttribute(odbc, attr2, attrName, false, startComposeId);
							}
							else
							{
								cAttr2 = gcnew ComplexAttribute(odbc, attr1, attrName, true, startComposeId);
							}
						}
						else
						{
							int selectType = odbc->GetResInt(resList[i+31]);
							int selectAttrId = odbc->GetResInt(resList[i+36]);
							if (selectType == 0)
							{
								int iFirstSymbol = odbc->GetResInt(resList[i+32]);
								int nSymbols = odbc->GetResInt(resList[i+33]);
								if (attr1 == nullptr)
								{
									cAttr2 = gcnew ComplexAttribute(odbc, attr2, attrName, false, selectAttrId, iFirstSymbol, nSymbols);
								}
								else
								{
									cAttr2 = gcnew ComplexAttribute(odbc, attr1, attrName, true, selectAttrId, iFirstSymbol, nSymbols);
								}
							}
							else
							{
								String^ splitSymbols = OdbcClass::GetResString(resList[i+34]);
								int usePart = odbc->GetResInt(resList[i+35]);
								if (attr1 == nullptr)
								{
									cAttr2 = gcnew ComplexAttribute(odbc, attr2, attrName, false, selectAttrId, splitSymbols, usePart);
								}
								else
								{
									cAttr2 = gcnew ComplexAttribute(odbc, attr1, attrName, true, selectAttrId, splitSymbols, usePart);
								}
							}

						}
					}
					AttributePair^ attrPair = gcnew AttributePair(odbc, parametrsId, attr1, attr2, cAttr1, cAttr2);
					list->Add(attrPair);
				}
			}

			return list;
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AttributePair() 
		{

		}


	};
}