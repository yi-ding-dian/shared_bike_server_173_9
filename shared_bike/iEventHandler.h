#ifndef NS_IEVENT_HANDLER_H_
#define NS_IEVENT_HANDLER_H_
#include "ievent.h"
#include "eventtype.h"

class iEventHandler
{
public:
	//�麯����������ָ������ָ��ġ��������͡�ȷ�����õĺ���������ָ�������
	virtual iEvent* handle(const iEvent* ev) {	return NULL; };

	iEventHandler(std::string name):name_(name) {};
	virtual ~iEventHandler() {};
	std::string& get_name() { return name_; }
	

private:
	std::string name_;
};


#endif // !NS_IEVENT_HANDLER_H_
