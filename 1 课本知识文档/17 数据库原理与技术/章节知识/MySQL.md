# 1 基础篇
## 1-1 MySQL 的安装与启动
- MySQL 可以设置为开机自启
- **停止 MySQL** 
	- *方法 1*：管理员身份在终端中输入 `net stop mysql80`
	- *方法 2*：`win+r` 再输入 `services.msc` 并找到 `MySQL`，手动停止
- **启动 MySQL** 
	- *方法 1*：管理员身份在终端中输入 `net start mysql80`
	- *方法 2*：cmd中输入 `services.msc` 并找到 `MySQL`，手动启动
- **客户端连接** 
	- *方式 1*：使用 MySQL 提供的客户端命令行工具 MySQL 8.0 Command Line Client，在里面输入密码即可。
	- *方式 2*：使用系统自带的命令行工具执行指令，在终端中输入 `mysql [-h 127.0.0.1] [-P 3306] -u root -p` (使用这种方式时，需要配置 PATH 环境变量)