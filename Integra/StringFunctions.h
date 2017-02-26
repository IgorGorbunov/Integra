#pragma once


namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Threading;

	/// <summary>
	/// Класс для р
	/// </summary>
	public ref class StringFunctions
	{

	public:
		static Char GetEngString(Char c) 
		{
			// А
			if (c == 1040 || c == 1072)
			{
				return 'F';
			}
			// Б
			else if (c == 1041 || c == 1073)
			{
				return ',';
			}
			// В
			else if (c == 1042 || c == 1074)
			{
				return 'D';
			}
			// Г
			else if (c == 1043 || c == 1075)
			{
				return 'U';
			}
			// Д
			else if (c == 1044 || c == 1076)
			{
				return 'L';
			}
			// Е
			else if (c == 1045 || c == 1077)
			{
				return 'T';
			}
			// Ж
			else if (c == 1046 || c == 1078)
			{
				return ';';
			}
			// З
			else if (c == 1047 || c == 1079)
			{
				return 'P';
			}
			// И
			else if (c == 1048 || c == 1080)
			{
				return 'B';
			}
			// Й
			else if (c == 1049 || c == 1081)
			{
				return 'Q';
			}
			// К
			else if (c == 1050 || c == 1082)
			{
				return 'R';
			}
			// Л
			else if (c == 1051 || c == 1083)
			{
				return 'K';
			}
			// М
			else if (c == 1052 || c == 1084)
			{
				return 'V';
			}
			// Н
			else if (c == 1053 || c == 1085)
			{
				return 'Y';
			}
			// О
			else if (c == 1054 || c == 1086)
			{
				return 'J';
			}
			// П
			else if (c == 1055 || c == 1087)
			{
				return 'G';
			}
			// Р
			else if (c == 1056 || c == 1088)
			{
				return 'H';
			}
			// С
			else if (c == 1057 || c == 1089)
			{
				return 'C';
			}
			// Т
			else if (c == 1058 || c == 1090)
			{
				return 'N';
			}
			// У
			else if (c == 1059 || c == 1091)
			{
				return 'E';
			}
			// Ф
			else if (c == 1060 || c == 1092)
			{
				return 'A';
			}
			// Х
			else if (c == 1061 || c == 1093)
			{
				return '[';
			}
			// Ц
			else if (c == 1062 || c == 1094)
			{
				return 'W';
			}
			// Ч
			else if (c == 1063 || c == 1095)
			{
				return 'X';
			}
			// Ш
			else if (c == 1064 || c == 1096)
			{
				return 'I';
			}
			// Щ
			else if (c == 1065 || c == 1097)
			{
				return 'O';
			}
			// Ъ
			else if (c == 1066 || c == 1098)
			{
				return ']';
			}
			// Ы
			else if (c == 1067 || c == 1099)
			{
				return 'S';
			}
			// Ь
			else if (c == 1068 || c == 1100)
			{
				return 'M';
			}
			// Э
			else if (c == 1069 || c == 1101)
			{
				return '\'';
			}
			// Ю
			else if (c == 1070 || c == 1102)
			{
				return '.';
			}
			// Я
			else if (c == 1071 || c == 1103)
			{
				return 'Z';
			}

			return ' ';
		}

		static double GetDouble(String^ s)
		{
			if (Thread::CurrentThread->CurrentCulture->NumberFormat->NumberDecimalSeparator == ",")
			{
				s = s->Replace(',', '.');
			}
			double d = double::Parse(s->Trim());
			d = Math::Round(d, 8);
			return d;
		}
	};
}