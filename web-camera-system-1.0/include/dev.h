/*
 * Author: liuwei
 * Date: 2013.10.11
 * 摄像头驱动模块头文件
 */
#ifndef _DEV_H_
#define _DEV_H_
#include <jpeglib.h>
#include <linux/videodev2.h>
#include <pthread.h>
#define COUNT_NUM 5
#define FPS 15
#define BUF_SIZE 4096
#define WIDTH 1280
#define HEIGHT 720

pthread_mutex_t mutex;
pthread_cond_t cond;
enum {MJPEG=V4L2_PIX_FMT_MJPEG,YUYV=V4L2_PIX_FMT_YUYV};
int pix_format;//camera init format
int flag;
typedef unsigned int size_t;
int camera_fd;//摄像头文件描述符号

typedef struct {
	unsigned char driver[16];
	unsigned char card[32];
	unsigned char bus_info[32];
	unsigned int version;

	unsigned int height;
	unsigned int width;
}Dev_info;
Dev_info dev;
	typedef struct videobuffer
	{
		void *start;
		size_t length;
	}videobuffer;
	videobuffer *buffers;
//设置二级缓存的全局变量
unsigned char *temp_buf;
int temp_len;
//获取摄像头的相关信息
extern void get_dev_info();

//打印摄像头的相关信息
extern void out_dev_info();

//设置视频捕获格式
extern void set_format();

//设置帧率
extern void set_parm();
//分配内存
extern void req_buf();

//获取物理地址并映射到用户空间
extern void query_buf_mmap();

//开始视频采集
extern void dev_on();

//采集一张图片保存到本地
extern void get_picture();

extern void send_picture();

extern void send_picture_th();

extern void get_picture_th();

//停止视频采集
extern void dev_off();

extern void *g_th();

extern void sig_handler();

extern void system_destroy();
//changed from yuyv format
typedef struct{
  struct jpeg_destination_mgr jpg_p;
  JOCTET*			buffer; 
  int				out_buf_size;
  int*				written; 
  unsigned char*	out_buf_cur;
  unsigned char*	out_buf;
}jpg_dst;

typedef jpg_dst *jpg_ptr;

//yuyv to jepg function
extern void dst_buffer(j_compress_ptr,unsigned char *,int ,int *);
extern int yuv_to_jpeg(unsigned char *,unsigned char *,int,int);
#endif
