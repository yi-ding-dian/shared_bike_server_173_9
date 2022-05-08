#ifndef BRKS_COMMON_ENENT_TYPE_H_
#define BRKS_COMMON_ENENT_TYPE_H_

#include "glo_def.h"

typedef struct EErrorReason_		
{
	i32 code;
	const char* reason;
}EErrorReason;

/*�¼�ID*/
enum EventID
{
	EEVENTID_GET_MOBILE_CODE_REQ		=	1,//��ȡ�ֻ���֤������
	EEVENTID_GET_MOBILE_CODE_RSP		=	2,//�ֻ���֤����Ӧ

	EEVENTID_REGISTER_USER_REQ			=	3,//�û�ע������
	EEVENTID_REGISTER_USER_RSP			=	4,//�û�ע����Ӧ

	EEVENTID_LOGIN_REQ					=	5,//��½����
	EEVENTID_LOGIN_RSP					=	6,//��½��Ӧ

	EEVENTID_RECHARGE_REQ				=	7,//�������
	EEVENTID_RECHARGE_RSP				=	8,//�����Ӧ

	EEVENTID_SCANQRSTART_REQ			=	9,//����ɨ�迪ʼ��������
	EEVENTID_SCANQRSTART_PSP			=	10,//����ɨ�迪ʼ������Ӧ

	EEVENTID_SCANQREND_REQ				=	11,//����ɨ�������������
	EEVENTID_SCANQREND_PSP				=	12,//����ɨ�����������Ӧ

	EEVENTID_FAULT_REQ					=	13,//����ɨ����ϱ�������
	EEVENTID_FAULT_PSP					=	14,//����ɨ����ϱ�����Ӧ

	EEVENTID_REPAIRFINISH_REQ			=	15,//����ɨ���޸��������
	EEVENTID_REPAIRFINISH_PSP			=	16,//����ɨ���޸������Ӧ

	EEVENTID_GET_ACCOUNT_BALANCE_REQ	=	21,//��ȡ�˺��������
	EEVENTID_ACCOUNT_BALANCE_RSP		=	22,//�˺������Ӧ

	EEVENTID_LIST_ACCOUNT_RECORDS_REQ	=	23,//��ȡ�˻���¼����
	EEVENTID_ACCOUNT_RECORDS_RSP		=	24,//�˻���¼��Ӧ

	EEVENTID_LIST_TRAVELS_REQ			=	25,//��ȡ�㼣����
	EEVENTID_LIST_TRAVELS_RSP			=	26,//�㼣��Ӧ

	EEVENTID_BROADCAST_MSG_REQ			=	27,//�㲥����
	EEVENTID_BROADCAST_MSG_RSP			=	28,//�㲥��Ӧ

	EEVENTID_LIST_BIKEINFO_REQ			=   29,//�������е�����Ϣ����
	EEVENTID_LIST_BIKEINFO_RSP			=   30,//�������е�����Ϣ��Ӧ

	EEVENTID_ADDBIKE_REQ				=	31,//��ӵ�������
	EEVENTID_ADDBIKE_RSP				=	32,//��ӵ�����Ӧ

	EEVENTID_DELETEBIKE_REQ				=	33,//ɾ����������
	EEVENTID_DELETEBIKE_RSP				=	34,//ɾ��������Ӧ

	EEVNETID_EXIT_RSP = 0xFE,
	EEVNETID_UNKOWN = 0xFF
};

typedef enum BikeStatus_
{
	BIKE_RIDE_START		= 1,	//����ɨ�뿪ʼ���У�����ʹ����
	BIKE_RIDE_END		= 2,	//����ɨ��������У��ָ�����״̬
	BIKE_FAULT			= 3,	//����ɨ����ϱ��ޣ����ڹ���״̬
	BIKE_REPAIR_FINISH  = 4,    //����ɨ���޸���ɣ��ָ�����״̬

}BikeStatus;


/*�¼���Ӧ�������*/
enum EErrorCode
{
	ERRC_SUCCESS = 200,
	ERRC_INVALID_MSG = 400,
	ERRC_INVALID_DATA = 404,
	ERRC_METHOD_NOT_ALLOWED = 405,
	ERRO_PROCCESS_FALED = 406,
	ERRO_BIKE_IS_TOOK = 407,
	ERRO_BIKE_IS_RUNNING = 408,
	ERRO_BIKE_IS_DAMAGED = 409,
	ERRO_NULL = 0

};

const char* getReasonByErrorCode(i32 code);

#endif // !BRKS_COMMON_ENENT_TYPE_H_
