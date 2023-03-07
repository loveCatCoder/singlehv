#include "event/hloop.h"

// 定时器回调函数
static void on_timer(htimer_t* timer) {
    printf("time=%lus\n", (unsigned long)time(NULL));
}


#if 0
int main() {
    // 新建一个事件循环结构体
    hloop_t* loop = hloop_new(0);

    // 添加一个定时器
    htimer_add(loop, on_timer, 1000, INFINITE);

    // 运行事件循环
    hloop_run(loop);

    // 释放事件循环结构体
    hloop_free(&loop);
    return 0;
}
#endif


void on_close(hio_t* io) {
}

void on_recv(hio_t* io, void* buf, int readbytes) {
	// 回显数据
    hio_write(io, buf, readbytes);
}

void on_accept(hio_t* io) {
	// 设置close回调
    hio_setcb_close(io, on_close);
    // 设置read回调
    hio_setcb_read(io, on_recv);
    // 开始读
    hio_read(io);
}

int main(int argc, char** argv) {
    
    int port = 8888;

    printf("tcp server listening :%d\n",port);
    // 创建事件循环
    hloop_t* loop = hloop_new(0);
    // 添加一个定时器
    htimer_add(loop, on_timer, 1000, INFINITE);
    // 创建TCP服务
    hio_t* listenio = hloop_create_tcp_server(loop, "0.0.0.0", port, on_accept);
    if (listenio == NULL) {
        return -20;
    }
    // 运行事件循环
    hloop_run(loop);
    // 释放事件循环
    hloop_free(&loop);
    return 0;
}


