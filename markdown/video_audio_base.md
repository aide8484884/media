###音视频编码的基本原理学习


##视频

1.视频信号的采样率 × 量化的比特  = 码率，从摄像头获取到的原始码率是很高的，所以必须要对其进行压缩编码。

2.视频得以进行压缩编码的原因是，视频中具有很多信息的冗余。去除这些冗余并不会对视频数据有特别明显的改变，
应次才有了视频压缩的可能。

3.变换编码，首先将基于空间的原始数据分割成8×8的小块，在这些小块上进行基于 离散余弦变换 DST 的变换处理。
然后把变换过的数据进行合理的量化。

4.熵编码，的到了量化以后的数据，就可以在这些数据之上进行熵编码，通过概率的方式，进行游程编码，然后再将
游程编码的结果进行哈夫曼编码这种变长编码，进一步提高视频压缩率。

5.运动估计和运动补偿，运动估计是指，结合I帧 或者前后帧搜索最为相似的块的过程，运动补偿是指将运动估计中
获取的运动矢量，将矢量区域和参考图像的最相似区域相减得到残差块的过程叫做运动补偿。

I帧：intra B帧 Bidirection prediction P帧 Prediction 

压缩率 B > P > I

6.混合编码的过程：
	输入的数据首先分块，然后经过运动估计和补偿，得到的差值在进行 DST 和量化，量化以后在进行熵编码。

##音频

1.音频信号的采样率 × 量化的比特 = 码率 ，原始码率依然很高，所以需要进行压缩编码。

2.音频编码的内容比较少，主要是将数据中的冗余去掉，一方面去掉音频数据频谱中我们人类听不到的部分，另一方面
在出现强弱音信号时，屏蔽听不到的弱音信号。



