# SPT Fuyu

[English](README.md)

## 下载

您也可以使用我们的在线修补器版本[SPT Fuyu Patcher Web](https://tkm.icu/SPT_Fuyu_Patcher_Web/)，它是基于修补启动器可执行文件实现的，因此可能在启动器更新后需要更新

您可以在 [Release](https://github.com/M3351AN/SPT-Fuyu/releases) 页面获取预构建的版本

如果您所在的地区无法正常访问Github，您可以通过 [CloudFlare CDN代理的镜像站](https://cdn.tkm.icu/SPT-Fuyu/) 进行下载

## SPT Fuyu是什么?

![download](https://github.com/user-attachments/assets/f1ac2e38-3787-46f1-baf9-1dc885cc7066)

*"人们不想买一个四分之一英寸的钻头。他们想要的是一个四分之一英寸的孔！" -- 西奥多·莱维特*

SPT Fuyu 是一款用于在没有从BSG或Steam安装塔科夫的情况下快速跳过SPT启动器在线版塔科夫安装验证的工具

最后在 SPT 4.0.7 经过测试

## 功能

- 跳过SPT启动器的游戏安装验证

## 与其他拥有相同/类似功能工具的区别

我们在SPT启动器运行时对验证相关的注册表/文件系统WindowsAPI进行挂钩

- 这样不再会在您的电脑中留下多余的文件
- 不再需要“也许是危险的”权限去修改您的注册表
- 即便您日后希望安装在线版EFT，这么做可以将您为了SPT造成的文件、注册表残留减少
- 从原理上，这可以更广泛的适应后续版本而无需更新
- 只需要保持dll文件存在，无需在每次更新后手动修补

## 如何使用?

### 方式1

1.将user32.dll放到SPT启动器所在的文件夹

2.每次运行SPT启动器，SPT Fuyu都会自动完成挂钩步骤

3.如果您发现SPT启动器的窗口标题变为“SPT.Fuyu.Launcher”，则说明挂钩步骤加载成功

<img width="294" height="240" alt="image" src="https://github.com/user-attachments/assets/c6400cd4-ff42-4bb0-805f-6c7568f2ad1b" />

### 方式2（Debug用途）

1.在Debug配置下编译

2.使用任意DLL映射器将生成的DLL映射到SPT启动器进程

3.SPT Fuyu会在注入后自动完成挂钩步骤

4.如果您发现SPT启动器的窗口标题变为“SPT.Fuyu.Launcher”，则说明挂钩步骤加载成功

<!--[![How to Use](https://res.cloudinary.com/marcomontalbano/image/upload/v1729199697/video_to_markdown/images/youtube--N-wXnwR-FiY-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://www.youtube.com/watch?v=N-wXnwR-FiY "How to Use")-->

## 这是怎么实现的？

众所周知，在SPT启动器的验证函数中，通过检查注册表项目和对应文件是否存在来进行验证是否安装了在线版EFT

在传统的方法中（例如SPT Fuyu的1.0版本），我们通过创建对应的注册表项和占位文件来通过这一验证

现在我们通过挂钩所使用的WindowsAPI，在挂钩函数中模拟存在对应的注册表项和文件来“欺骗”SPT启动器

解决问题

## 致谢

[SPT Development Repo](https://dev.sp-tarkov.com/)

[ILSpy](https://github.com/icsharpcode/ILSpy)

[minhook](https://github.com/TsudaKageyu/minhook)

[dll proxy generator](https://github.com/maluramichael/dll-proxy-generator)

## 声明

此处所指的"SPT Fuyu"仅指代本项目，与其他任何项目无关，即便名字相同或类似

SPT Fuyu 只是一款与 SPT项目 / Battlestate Games Ltd. 公司 以及其他任何项目、组织、个人 在任何情况、任何形式下都无关的软件

该软件为教育目的开发，仅供学习，不为使用者宣传破解软件、破坏他人知识产权的行为背书

SPT Fuyu的所有内容仅限在[TOSSRCU License](https://github.com/M3351AN/SPT-Fuyu/blob/main/LICENSE)许可约束下使用
