#pragma once
#ifndef FILEWR_H
#define FILEWR_H
#include "pch.h"
#include "FileWR.h"
#include <iostream>
#include "People.h"
using namespace Windows::Storage;
using namespace concurrency;
using namespace std;
using namespace Platform;

// 作为工具类，提供读写文件工具
class FileWR
{

private:
	/*static void setString(String ^str)
	{
		content = str;
	}*/

public:
	//static String ^content;

	static void FileWrite(String^ path, String^ content)
	{
		StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
		concurrency::create_task(storageFolder->CreateFileAsync(path, CreationCollisionOption::ReplaceExisting))
			.then([&, content](StorageFile^ File)
		{
			return FileIO::WriteTextAsync(File, content);
		}).then([&](task<void> previousOperation) {
			try {
				previousOperation.get();

			}
			catch (Platform::Exception^) {
				// 写入失败
			}
		});
	};


	static void FileAppend(String^ path, String^ content)
	{
		StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
		concurrency::create_task(storageFolder->CreateFileAsync(path, CreationCollisionOption::OpenIfExists))
			.then([&, content](StorageFile^ File)
		{
			return FileIO::AppendTextAsync(File, content);
		}).then([](task<void> previousOperation) {
			try {
				previousOperation.get();
			}
			catch (Platform::Exception^) {
				// 写入失败

			}
		});

	};


	static String^ FileRead(String^ path)
	{
		StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
		concurrency::create_task(storageFolder->GetFileAsync(path))
			.then([&](StorageFile^ file)
		{
			return FileIO::ReadTextAsync(file);
		}).then([&](concurrency::task<String^> previousOperation) {
			try {
				// 读取成功
				//setString(previousOperation.get());
				People::fileContent = previousOperation.get();
			}
			catch (...) {
				// 读取失败
			}
		});
		String^ tmp2 = People::fileContent;
		return People::fileContent;
	}
};


#endif // !FILEWR