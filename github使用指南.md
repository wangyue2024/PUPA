# GitHub 基础使用指南

> 大家应当学会使用github，以后写了题解或者代码或者小结或者整理了模板 可以交一份上来

## 第一部分：一次性环境准备

在开始提交作业前，你只需要做一次以下准备工作。

### 1. 在你的电脑 安装 Git

### 2. 配置 Git

安装完成后，打开你的终端，输入以下两条命令

```bash
# 把 "Your Name" 换成你的真实姓名或 GitHub 用户名
git config --global user.name "Your Name"

# 把 "your_email@example.com" 换成你注册 GitHub 时用的邮箱
git config --global user.email "your_email@example.com"
```


## 第二部分：克隆，拉取和提交

### 步骤 1：Clone - 把共享仓库下载到你的电脑 (仅第一次需要)

找个合适的文件夹，打开终端，输入

```bash
git clone https://github.com/wangyue2024/PUPA.git
```
会创建PUPA文件夹
### 步骤 2：Pull - 你做任何事情之前，先同步

在PUPA文件夹内 执行
```bash
git pull
```

### 步骤 3：Add & Commit 选择，封存文件

   ```bash
   # 告诉 Git 你要管理哪些文件（. 代表所有修改过的文件）
   git add .

   # 正式提交，并写下本次提交的说明（-m 是提交内容的说明）
   git commit -m "XX题解" 
   ```

### 步骤 4：Push - 提交到 GitHub


```bash
git push
```

有其他问题去找LLM