# SPT Fuyu
[简体中文](README_CN.md)

## Download

You can get the latest pre-built version in [Release](https://github.com/M3351AN/SPT-Fuyu/releases)

If you are in a region where Github is not accessible, you can download it through the [mirror of CloudFlare CDN proxy](https://cdn.tkm.icu/SPT-Fuyu/).

## What is SPT Fuyu?

![download](https://github.com/user-attachments/assets/f1ac2e38-3787-46f1-baf9-1dc885cc7066)

SPT Fuyu is a tool developed to quickly bypass EFT install validate of SPT while u have not install EFT from BSG

last tested in SPT 4.0.1

## Functions

- bypass EFT install validate of SPT Installer & Launcher

## Differences from other tools with the same/similar functionality

We patch the SPT launcher directly

- This eliminates the need for unnecessary files on your computer
- No longer requires potentially dangerous registry modifications
- Even if you later decide to install the live version of EFT, this minimizes the amount of files and registry artifacts left behind while using SPT.

## How to use?

### Method 1
1. Place SPT.Fuyu.Patcher.exe in the same folder as the SPT Launcher.

2. Double-click SPT.Fuyu.Patcher.exe to run it. SPT Fuyu will automatically complete the patching process.

### Method 2
1. Drag the SPT Launcher file (i.e., SPT.Launcher.exe) onto SPT.Fuyu.Patcher.exe.

2. SPT Fuyu will automatically complete the patching process.

<!--[![How to Use](https://res.cloudinary.com/marcomontalbano/image/upload/v1729199697/video_to_markdown/images/youtube--N-wXnwR-FiY-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://www.youtube.com/watch?v=N-wXnwR-FiY "How to Use")-->

## How is this made?

As we all know, the SPT launcher is based on .NET 9. Earlier versions (prior to 4.0.0) were based on even earlier versions of .NET. However, the principles are the same. When the program is launched, the CLR takes over execution, and then the JIT compiler converts the IL into native machine code.

Our patching begins with the IL.

First, we use the ILSpy tool to find the code for the validation function, which is here (the same [source code](https://github.com/sp-tarkov/launcher/blob/master/project/SPT.Launcher.Base/Helpers/ValidationUtil.cs) has been open-sourced by the SPT team and can be seen to be almost identical)

<img width="1233" height="855" alt="image" src="https://github.com/user-attachments/assets/3d08890a-eba2-4bd8-b518-5a9ab924565f" />

Then we switch to the IL view and see the following IL code

<img width="237" height="115" alt="image" src="https://github.com/user-attachments/assets/4398d50a-0dca-43fd-a0b3-5006904ef7b1" />

It corresponds to
```
07
16
FE 01
2A
```
The key lies in the two bytes `07` and `16`. In the IL code, they represent ldloc.1 (load local variable 1) and ldc.i4.0 (push constant 0), which constitute the two terms of the equality check.

If we change to
```
16
16
FE 01
2A
```
and we get

<img width="224" height="127" alt="image" src="https://github.com/user-attachments/assets/04413daf-6fbf-4bbc-97b5-904c5a09719f" />

Obviously, this always returns "true"

Similarly, change to
```
07
07
FE 01
2A
```

<img width="256" height="129" alt="image" src="https://github.com/user-attachments/assets/58676453-0dd9-4076-b07e-60740e823a01" />

This will always return true.

The next step is to locate the location of this byte sequence. You can search for it using any binary editor, but if you search directly for `07 16 FE 01 2A` you will get at least 4 results.

<img width="1201" height="126" alt="image" src="https://github.com/user-attachments/assets/1ee7e0bd-a4ec-403d-a6a8-ebcfe0acf586" />

But at the same time, we noticed that there is a `leave.s IL_00d4` statement before this code

<img width="467" height="371" alt="image" src="https://github.com/user-attachments/assets/67c93fec-c8ae-4e3a-bd35-eb5d84a653f6" />

Therefore, we can determine the position of 1C0B942 in the figure, that is, `DE 00 07 16 FE 01 2A` corresponds to the position we want to find. To ensure stability, we take the pattern to `26 15 0B DE 00 07 16 FE 01 2A`

Profit

## Credits

[SPT Development Repo](https://dev.sp-tarkov.com/)

[ILSpy](https://github.com/icsharpcode/ILSpy)

## Declaration
"SPT Fuyu" mentioned here refers only to this project and has nothing to do with any other projects, even if the names are the same or similar.

SPT Fuyu is just a software that not affiliated with SPT / Battlestate Games Ltd. and any other project, organization, individual in any way.

This software is produced for educational purposes only and is not intended to promote cracked software or destroy other people's intellectual property rights.

All content of SPT Fuyu is subject to the [TOSSRCU License](https://github.com/M3351AN/SPT-Fuyu/blob/main/LICENSE)
