#include "pch.h"
#include "DBconnector.h"


DBconnector::DBconnector()
{	
}

DBconnector::~DBconnector()
{
}

//bool DBconnector::Initialize()
//{
//	retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
//
//	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
//	{
//		retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER*)SQL_OV_ODBC3, SQL_IS_INTEGER);
//		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
//			return true;
//		else return false;
//
//	}
//}
//
//void DBconnector::DBconnect()
//{
//	retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
//	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
//	{
//		SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0);
//		retcode = SQLConnect(hdbc, (SQLWCHAR *)"my_game", SQL_NTS, (SQLWCHAR*) "sa", SQL_NTS, (SQLWCHAR*)"123", SQL_NTS);
//
//		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
//			retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
//
//			retcode = SQLExecDirect(hstmt, (SQLWCHAR *)"Select ID  from Login", SQL_NTS);
//			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
//
//				retcode = SQLBindCol(hstmt, 1, SQL_C_CHAR, &sCustID, 100, &cbCustID);
//				//retcode = SQLBindCol(hstmt, 2, SQL_INTEGER, num, NAME_LEN, &cbName);
//				retcode = SQLFetch(hstmt);
//				wprintf(L"%d: %S \n", 10, sCustID);
//
//				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
//					SQLCancel(hstmt);
//					SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
//				}
//				SQLDisconnect(hdbc);
//			}
//			SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
//		}
//	}
//	SQLFreeHandle(SQL_HANDLE_ENV, henv);
//}