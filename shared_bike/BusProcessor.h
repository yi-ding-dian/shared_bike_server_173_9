#ifndef __BUSPROCESSOR_H_
#define __BUSPROCESSOR_H_

#include <memory>
#include "user_event_handler.h"
#include "sqlconnection.h"
#include "SqlTables.h"

class BusinessProcessor
{
public:
	/*����ָ����ָ��̬����(��)����ָ�룬���������ڿ��ƣ��ܹ�ȷ���Զ���ȷ�����ٶ�̬����Ķ��󣬷�ֹ�ڴ�й¶��
		����һ��ͨ��ʵ�ּ�����ʹ�����ü�����ÿ��ʹ�������ڲ������ü�����1��
		ÿ������һ�Σ��ڲ����ü�����1����Ϊ0ʱ��ɾ����ָ��Ķ��ڴ�
		shared_ptr���ڡ����ü�����ģ��ʵ�֣����shared_ptr��ָ��ͬһ����̬���󣬲�ά��һ����������ü�������
		��¼������ͬһ�����shared_ptrʵ���������������һ��ָ��̬�����shared_ptr����ʱ��
		���Զ���������ָ����(ͨ��delete������
	*/
	BusinessProcessor(std::shared_ptr<MysqlConnection> sqlconn);
	virtual ~BusinessProcessor();

	bool init();

private:
	std::shared_ptr<MysqlConnection> mysqlconn_;
	//MysqlConnection* mysqlcon;
	std::shared_ptr<UserEventHandler> ueh_;
};


#endif // !__BUSPROCESSOR_H_
