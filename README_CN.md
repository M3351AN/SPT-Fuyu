# SPT Fuyu
[English](README.md)

## 下载

您可以在 [Release](https://github.com/M3351AN/SPT-Fuyu/releases) 页面获取预构建的版本

如果您所在的地区无法正常访问Github，您可以通过 [CloudFlare CDN代理的镜像站](https://cdn.tkm.icu/SPT-Fuyu/) 进行下载

## SPT Fuyu是什么?

![download](https://github.com/user-attachments/assets/f1ac2e38-3787-46f1-baf9-1dc885cc7066)

SPT Fuyu 是一款用于在没有从BSG安装塔科夫的情况下快速跳过SPT启动器在线版塔科夫安装验证的工具

最后在 SPT 4.0.1 经过测试

## 功能

- 跳过SPT安装包/启动器的游戏安装验证

## 与其他拥有相同/类似功能工具的区别

我们将直接修补SPT启动器

- 这样不再会在您的电脑中留下多余的文件
- 不再需要“也许是危险的”权限去修改您的注册表
- 即便您日后希望安装在线版EFT，这么做可以将您为了SPT造成的文件、注册表残留减少

## 如何使用?

### 方式1
1.将SPT.Fuyu.Patcher.exe放到SPT启动器所在的文件夹

2.双击运行SPT.Fuyu.Patcher.exe，SPT Fuyu会自动完成修补步骤

### 方式2
1.将SPT启动器文件（也就是SPT.Launcher.exe）拖拽到SPT.Fuyu.Patcher.exe

2.SPT Fuyu会自动完成修补步骤

<!--[![How to Use](https://res.cloudinary.com/marcomontalbano/image/upload/v1729199697/video_to_markdown/images/youtube--N-wXnwR-FiY-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://www.youtube.com/watch?v=N-wXnwR-FiY "How to Use")-->


## 这是怎么实现的？

众所周知，SPT的启动器是一个基于.NET 9的程序，在较早的版本中（4.0.0 以前）基于.NET的更早版本。但它们的原理都是相同的。启动程序时，CLR会接管执行，然后通过JIT编译器，把IL转换成本机机器码。

而我们的修补则从IL入手。

我们首先利用ILSpy工具找到验证函数的代码，它在这里（同样的[源码](https://github.com/sp-tarkov/launcher/blob/master/project/SPT.Launcher.Base/Helpers/ValidationUtil.cs)已经由SPT团队开源，可以看到几乎一致）

<img width="1233" height="855" alt="image" src="https://github.com/user-attachments/assets/3d08890a-eba2-4bd8-b518-5a9ab924565f" />

接着我们切换到IL视图，得到了这样的IL代码

<img width="237" height="115" alt="image" src="https://github.com/user-attachments/assets/4398d50a-0dca-43fd-a0b3-5006904ef7b1" />

它所对应的就是
```
07
16
FE 01
2A
```
关键在于 `07` 和 `16` 这两个字节，在IL代码中，它们分别代表 ldloc.1 （加载局部变量1）和 ldc.i4.0（压入常量 0），它们组成了相等判断的两项.

如果我们改为
```
16
16
FE 01
2A
```
得到的就是

<img width="224" height="127" alt="image" src="https://github.com/user-attachments/assets/04413daf-6fbf-4bbc-97b5-904c5a09719f" />

显然，这永远返回“真”

同理，改为
```
07
07
FE 01
2A
```

<img width="256" height="129" alt="image" src="https://github.com/user-attachments/assets/58676453-0dd9-4076-b07e-60740e823a01" />

这一样会永远返回真。

接着就是定位这段字节序列所在的位置，只需要使用随意哪个二进制编辑器进行搜索，但如果直接搜索`07 16 FE 01 2A`我们会得到至少4个结果

<img width="1201" height="126" alt="image" src="https://github.com/user-attachments/assets/1ee7e0bd-a4ec-403d-a6a8-ebcfe0acf586" />

但与此同时，我们注意到在这段代码前还有`leave.s IL_00d4`语句

<img width="467" height="371" alt="image" src="https://github.com/user-attachments/assets/67c93fec-c8ae-4e3a-bd35-eb5d84a653f6" />

因此可以确定图中1C0B942位置，即`DE 00 07 16 FE 01 2A`对应的就是我们要找到的位置，保险起见我们取特征码到`26 15 0B DE 00 07 16 FE 01 2A`

解决问题


## 致谢

[SPT Development Repo](https://dev.sp-tarkov.com/)
[ILSpy](https://github.com/icsharpcode/ILSpy)

## 声明
此处所指的"SPT Fuyu"仅指代本项目，与其他任何项目无关，即便名字相同或类似

SPT Fuyu 只是一款与 SPT项目 / Battlestate Games Ltd. 公司 以及其他任何项目、组织、个人 在任何情况、任何形式下都无关的软件

该软件为教育目的开发，仅供学习，不为使用者宣传破解软件、破坏他人知识产权的行为背书

SPT Fuyu的所有内容仅限在[TOSSRCU License](https://github.com/M3351AN/SPT-Fuyu/blob/main/LICENSE)许可约束下使用
