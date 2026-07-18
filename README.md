# SPT Fuyu

[简体中文](README_CN.md)

## Download

You can also use our web patcher version [SPT Fuyu Patcher Web](https://tkm.icu/SPT_Fuyu_Patcher_Web/), which is implemented based on the patching of the launcher executable file. Therefore, it may need to be updated after SPT launcher updated

You can get the latest pre-built version in [Release](https://github.com/M3351AN/SPT-Fuyu/releases)

If you are in a region where Github is not accessible, you can download it through the [mirror of CloudFlare CDN proxy](https://cdn.tkm.icu/SPT-Fuyu/).

## What is SPT Fuyu?

![download](.github/icon-rusted.png)

*"People don't want to buy a quarter-inch drill. They want a quarter-inch hole!" -- Theodore Levitt*

SPT Fuyu is a tool developed to quickly bypass EFT install validate of SPT while u have not install EFT from BSG or Steam

last tested in SPT 4.0.13

## Functions

- bypass EFT install validate of SPT Launcher

## Differences from other tools with the same/similar functionality

We hook the .NET JIT compiler's `compileMethod` during the runtime of the SPT launcher, replacing the IL of `SPT.Launcher.Helpers.ValidationUtil.Validate()` with `ldc.i4.1; ret` so it always returns `true`

- This eliminates the need for unnecessary files on your computer
- No longer requires potentially dangerous registry modifications
- Even if you later decide to install the live version of EFT, this minimizes the amount of files and registry artifacts left behind while using SPT.
- In principle, this can be more widely applied to subsequent versions without requiring updates
- It is only necessary to ensure the existence of the dll file, without the need to manually patch it after each update

## How to use?

### Method 1

1. Place DWrite.dll in the folder where the SPT launcher is located

2. Every time the SPT launcher is run, the SPT Fuyu will automatically complete the hooking setup

3. If you notice that the window title of the SPT launcher has changed to "SPT.Fuyu.Launcher", it indicates that the hooking step has been successfully loaded

<img width="294" height="240" alt="image" src="https://github.com/user-attachments/assets/c6400cd4-ff42-4bb0-805f-6c7568f2ad1b" />

### Method 2 (for Debugging)

1. Compile under Debug configuration

2. Use any DLL mapper to map the generated DLL to the SPT launcher process

3. SPT Fuyu will automatically complete the hooking step after injection

4. If you notice that the window title of the SPT launcher has changed to "SPT.Fuyu.Launcher", it indicates that the hooking step has been successfully loaded

<!--[![How to Use](https://res.cloudinary.com/marcomontalbano/image/upload/v1729199697/video_to_markdown/images/youtube--N-wXnwR-FiY-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://www.youtube.com/watch?v=N-wXnwR-FiY "How to Use")-->

## How is this made?

SPT Launcher is a .NET application. Its `SPT.Launcher.Helpers.ValidationUtil.Validate()` method checks whether the online version of EFT is installed

We hook the .NET JIT compiler's `compileMethod` function via `clrjit.dll`'s `getJit()` vtable. When the JIT is about to compile `Validate()`, we replace its IL code with `ldc.i4.1; ret`, making it always return `true` — bypassing the installation check entirely

## Credits

[SPT Development Repo](https://dev.sp-tarkov.com/)

[ILSpy](https://github.com/icsharpcode/ILSpy)

[ilhook](https://github.com/regomne/ilhook-rs)

## Declaration

"SPT Fuyu" mentioned here refers only to this project and has nothing to do with any other projects, even if the names are the same or similar.

SPT Fuyu is just a software that not affiliated with SPT / Battlestate Games Ltd. and any other project, organization, individual in any way.

This software is produced for educational purposes only and is not intended to promote cracked software or destroy other people's intellectual property rights.

All content of SPT Fuyu is subject to the [BSD-3-Clause License](https://github.com/M3351AN/SPT-Fuyu/blob/main/LICENSE.txt)
