#ifndef __SQLTABLES_H_
#define __SQLTABLES_H_
#include "sqlconnection.h"
#include <memory>
#include "glo_def.h"

class SqlTables
{
public:
	SqlTables(std::shared_ptr<MysqlConnection> sqlconn) :sqlconn_(sqlconn)
	{

	}
	//~SqlTables();

	bool CreateUserInfo()
	{
		LOG_DEBUG("���ڴ����û���Ϣ��......");
		const char* pUserInfoTable = "\
								CREATE TABLE IF NOT EXISTS userinfo( \
								id			 int(16)			NOT NULL primary key auto_increment, \
								mobile		 varchar(16)		NOT NULL default '13000000000', \	
								username	 varchar(18)	    NOT NULL default 'bikeuser', \
								userpassword varchar(16)		NOT NULL, \
								registertime timestamp			NOT NULL default CURRENT_TIMESTAMP, \
								lastUsetime  timestamp			NOT NULL default '0000-00-00 00:00:00',\
								money		 int(4)				NOT NULL default 10, \
								INDEX		 mobile_index(mobile) \
								)";
		if (!sqlconn_->Execute(pUserInfoTable))
		{
			LOG_ERROR("create table userinfo table failed. error msg:%s", sqlconn_->GetErrInfo());
			return false;
		}
		LOG_DEBUG("�û���Ϣ�����ɹ���");

		//����һ������Ա�˻�
		char sql_content[1024];
		sprintf(sql_content, "SELECT username FROM userinfo where username='qiniubike' and userpassword='qiniubike'");
		SqlRecordSet record_set;
		
		if (!sqlconn_->Execute(sql_content, record_set))
		{
			LOG_DEBUG("sql���ִ��ʧ�ܣ�����ԭ��[%s]", sqlconn_->GetErrInfo());
			return false;
		}

		MYSQL_ROW row = record_set.FetchRow();
		if (row == NULL)
		{
			memset(sql_content, '\0', sizeof(sql_content));
			sprintf(sql_content, "INSERT INTO userinfo(username, userpassword) VALUES('qiniubike', 'qiniubike')");
			if (!sqlconn_->Execute(sql_content))
			{
				LOG_DEBUG("����Ա��Ϣ����ʧ�ܣ�����ԭ��[%s]", sqlconn_->GetErrInfo());
				return false;
			}
		}

		return true;		
	}



	bool UserRideRecordInfo()
	{
		LOG_DEBUG("���ڴ����û�ʹ�õ�����¼��Ϣ��......");
		const char* pUserRideRecordInfoTable = "\
								CREATE TABLE IF NOT EXISTS user_ride_record_info( \
								id				int				NOT NULL primary key auto_increment, \
								mobile			varchar(128)    NOT NULL default '1300000000', \
								username		varchar(18)		NOT NULL,\
								bikeId			int(11)			NOT NULL,\
								bikeStatus		tinyint(2)		NOT NULL,\
								start_time		timestamp		NOT NULL default CURRENT_TIMESTAMP, \
								end_time	    timestamp		NOT NULL default '0000-00-00 00:00:00', \
								start_point		point			NOT NULL,			\
								end_point		point			NOT NULL,			\														
								comsume		    int				NOT NULL default 0, \
								balance		    int				NOT NULL default 0, \
								INDEX		mobile_index(mobile) \
								)";
		if (!sqlconn_->Execute(pUserRideRecordInfoTable))
		{
			LOG_ERROR("create table userinfo table failed. error msg:%s", sqlconn_->GetErrInfo());
			printf("create bikeinfo table  table failed. error msg:%s", sqlconn_->GetErrInfo());
			return false;
		}
		LOG_DEBUG("�û�ʹ�õ�����¼��Ϣ�����ɹ���");
		return true;
	}

	bool CreateBikeTable()
	{
		LOG_DEBUG("���ڴ���������Ϣ��......");
		const char* pBikeInfoTable = " \
						CREATE TABLE IF NOT EXISTS bikeinfo( \
						id			int				NOT NULL primary key auto_increment, \
						devno		int				NOT NULL, \
						status		tinyint(1)		NOT NULL default 0, \
						trouble		int				NOT NULL default 0, \
						tmsg		varchar(256)	NOT NULL default '', \
						time		timestamp		NOT NULL default CURRENT_TIMESTAMP, \
						bike_point	point			NOT NULL	\
						)";
		

		//const char* pBikeInfoTable = "create table if not exists bikeinfo(id int, name char(6));";
		if (!sqlconn_->Execute(pBikeInfoTable))
		{
			LOG_ERROR("create bikeinfo table failed. error msg:%s", sqlconn_->GetErrInfo());
			printf("create bikeinfo table failed. error msg:%s", sqlconn_->GetErrInfo());
			return false;
		}
		LOG_DEBUG("������Ϣ�����ɹ���");
		return true;

	}

private:
	std::shared_ptr<MysqlConnection> sqlconn_;
};


#endif // !__SQLTABLES_H_
