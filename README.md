# sigslot
开箱即用的sigslot

sig/slot机制就是对象之间发送和接收消息的机制。sigslot是一个线程安全、类型安全，用C++实现的sig/slot机制的开源代码库，只有sigslot.h一个头文件，基本功能有connect、disconnect及emit。

sig/slot可以带参数也可以不带，最多可以带8个参数。signal0<> xxx称之为sig，即用来发出信号，而继承has_slots<>的类的成员函数则称之为slot，即信号处理函数。sigslot的核心就在这里，就是通过建立对应关系来实现对象间的消息交互。sig是一个成员变量，它形如signal + n<type1, type2...>，后面的n表示signal可以接收几个参数，类型任意，最多为8个。

通过调用sig的connect函数建立sig和slot间的对应关系。connect函数接收两个参数，一个是消息目的对象的地址， 另一个是目的对象的成员函数指针。为了让整个机制有效运行，目的类必须从has_slots<>继承，并且sig/slot参数类型必须一致。也可以将一个sig连接到多个slot上，这样每次sig发出信号的时候，每个连接的slot都能收到该信号。

通过调用sig的disconnect函数断开sig和slot之间的连接，只有一个参数，即目的对象的地址。一般不需要显式调用disconnect函数，在sig类和目的类（包含slot函数的类）析构函数中将自动调用disconnect断开sig和slot的连接。也可使用disconnect_all断开该sig的所有slot。


sigslot主页: http://sigslot.sourceforge.net
sigslot文档: http://sigslot.sourceforge.net/sigslot.pdf
