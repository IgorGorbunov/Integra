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

	private:
		OdbcClass^ _odbc;

		String^ _name;
		String^ _sourceGroupId;
		String^ _sourceGroupName;
		String^ _targetGroupId;
		String^ _targetGroupName;

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