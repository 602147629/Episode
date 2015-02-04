#ifndef __CONNECTIONMANAGER_SERVER_CONNECTION_H__
#define __CONNECTIONMANAGER_SERVER_CONNECTION_H__

#include <boost/asio.hpp>
#include <list>

#include "Packet.h"
#include "Connection.h"

using namespace boost::asio;

/*
1. ����ĳ��ַ ip port
2. �Ͽ����Ӻ󣬲�ͣ���Լ�������
3. ���ӳɹ��󣬷���handshake��������ʱ��������
*/
class ServerConnection:public Connection
{
public:
	ServerConnection(boost::asio::io_service& io_service);
	~ServerConnection();
	void init(std::string ip, int port);
	void update();
protected:
	void connectHandler(const boost::system::error_code& e);
	void tick(const boost::system::error_code& e);	
	
	
	void tryConnect();
	void errHandler(const boost::system::error_code& e, Connection*, std::string dummy);
protected:
	std::string			m_ip;
	int					m_port;
	

	boost::asio::deadline_timer m_tickTimer;
};

#endif