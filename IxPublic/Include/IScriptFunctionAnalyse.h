//////////////////////////////////////////////////////////////////////////
//	@File		:	IScriptFunctionAnalyse.h
//	@Data		:	2015-12-22 15:25
//	@Author		:	IDeath
//	@Brief		:	������ʽ�ű�����
//
/*	��ȷ��ʽ��
					QStringList sListData;
					sListData.append("��ʼ1(98(585241.14541), 323(������))");
					sListData.append("��ʼ()");
					sListData.append("��ʼ1(��ʼ2,��ʼ3)");
					sListData.append("��ʼ1( ��ʼ2( ���� ), ��ʼ3(Ҳ��))");
					sListData.append("main()");
					sListData.append("main(  )");
					sListData.append(" main (  ) ");
					sListData.append(" _main ( dsdsdwew1, char( dsdsdwew2 ), dsdsdwew3, char  ( dsdsdwew4 ))");
					sListData.append("1main(char, int, jjj)");
					sListData.append("_main(char, int)");
					sListData.append(" _main (char, int)");
					sListData.append(" _main ( char , int )");
					sListData.append(" _main ( char, int(dsdw))");
					sListData.append(" 1main ( char , int(dsdw))");
					sListData.append(" _main ( char, int(dsdw))");
					sListData.append(" _main (1)");
	�����ʽ��
					sListData.append("��ʼ1(1.3.2)");
					sListData.append("��ʼ1(1.��)");
					sListData.append("��ʼ1(1.)");
					sListData.append("��ʼ1(.3)");
					sListData.append("��ʼ1(., ��ʼ3)");
					sListData.append("��ʼ1(.��ʼ2, .��ʼ3)");
					sListData.append("��ʼ1( ��ʼ2( ���� ), ��ʼ3(Ҳ��(����)))");
					sListData.append("��ʼ1(�� ʼ3)");
					sListData.append("��ʼ1(��ʼ2�� ��ʼ3)");
					sListData.append(" ��()");
					sListData.append("��()");
					sListData.append("-(323)");
					sListData.append("~(323)");
					sListData.append("!()");
					sListData.append("@()");
					sListData.append("#()");
					sListData.append("$()");
					sListData.append("%()");
					sListData.append(" * ()");
					sListData.append(" (()");
					sListData.append(" )(232()");
					sListData.append(" >()");
					sListData.append(" <()");
					sListData.append(" /()");
					sListData.append(" ?()");
					sListData.append(" '()");
					sListData.append("  (323  ) ");
					sListData.append(" main, (  ) ");
					sListData.append(" _main (,1)");
					sListData.append("main(dfd char,int)");
					sListData.append("main( sssd char argv )");
					sListData.append(" _main ( (1))");
					sListData.append("dsaewe");
					sListData.append("^dsaewe");
					sListData.append("^dsaewe()");
					sListData.append("dsaewe *7");
					sListData.append("[]");
					sListData.append("ds*()");
					
					if (pAnalyzer->Load(szData))
					{
						qDebug() << szData << "��������:" << pAnalyzer->Name();
						int nParamCount = pAnalyzer->GetParamCount();
						for (int i = 0; i < nParamCount; ++i)
						{
							qDebug() << "��������: " << pAnalyzer->GetParamType(i) << "  " << "����ֵ: " << pAnalyzer->GetParamValue(i);
						}
					}
					else
					{
						qDebug() << "��������" << szData;
					}
					*/
//////////////////////////////////////////////////////////////////////////
#ifndef IScriptFunctionAnalyse_h__
#define IScriptFunctionAnalyse_h__

#include "IScriptAnalyzer.h"
#include <list>
#include "PublicExport.h"

class PUBLIC_EXPORT IScriptFunctionAnalyse : public IScriptAnalyzer
{
public:
	IScriptFunctionAnalyse(){};
	virtual ~IScriptFunctionAnalyse(){};

	/**
	*	@brief	�����ű�
	*/
	virtual bool Load(const char *szScript, int nLen = 0) = 0;
	
	/**
	*	@brief	���ؽ�����ĺ������ơ�
	*/
	virtual const char* Name() = 0;
	
	/**
	*	@brief	���ؽ����������������
	*/
	virtual int GetParamCount() = 0;
	
	/**
	*	@brief	����ĳ�����������͡�
	*/
	virtual const char* GetParamType(int nIndex) = 0;
	
	/**
	*	@brief	����ĳ��������ֵ��
	*/
	virtual const char* GetParamValue(int nIndex) = 0;
	
	/**
	*	@brief	�������������ϳɺ�����
	*/
	virtual const char* CombinationFunction(const char* szFunctionName, std::list<const char*>& sListParam) = 0;
};
#endif // IScriptFunctionAnalyse_h__