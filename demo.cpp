#include <string>
#include <iostream>

#include "sigslot.h"
using namespace std;
using namespace sigslot;
 
// 信号发送者
class MessageSender {
public:
	void sendMsg() {
		string id = "000001";
		string name = "jack";
		msg_sig(id, name);
	}
public:
	// 定义一个包含两个参数的信号
	sigslot::signal2<string, string> msg_sig;
};
 
// 信号接收者，需要继承sigslot::has_slots<>
class MessageReceiver:public sigslot::has_slots<>{
public:
	// 处理信号
	void receiveMsg(string id,string name) {
		cout<<"id = "<<id<<" name = "<<name<<endl;
	}
};
 
int main()
{
	MessageSender sender;
	MessageReceiver receiver;
 
	// 绑定信号和槽
	sender.msg_sig.connect(&receiver, &MessageReceiver::receiveMsg);
 
	// 发送消息
	for (int i = 0; i < 5; ++i) {
		sender.sendMsg();
	}
    return 0;
}
