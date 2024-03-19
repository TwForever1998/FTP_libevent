﻿#ifndef FTP_H
#define FTP_H
#include <QObject>
#include <ftplib.h>
#include <vector>


struct FTP_LOGIN_DATA{
    QString host;
    QString user;
    QString pass;
};

struct FTP_FILE_INFO{
    QString access;//权限
    QString link_cnt;//链接数
    QString ower;//属主
    QString group;//属组
    QString size;//大小
    QString date;//日期(3)
    QString file_name;//文件名(last)
};

class Ftp
{
public:
    Ftp();
    ~Ftp();

public:
    bool login(const FTP_LOGIN_DATA& data);
    QString pwd();
    std::vector<FTP_FILE_INFO> dir();
    bool cd(const QString& path);
    bool cdup();
    bool put(const QString& put_file);
    bool get(const QString& get_file,const QString& remote_file);
    bool del(const QString& file);
    void quit();
    QString error();

private:
    ftplib* ftp;
    std::string cur_path;
};

#endif // FTP_H
