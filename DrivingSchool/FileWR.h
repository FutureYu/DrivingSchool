#pragma once
#ifndef FILEWR_H
#define FILEWR_H
#include "pch.h"
#include "People.h"
using namespace Windows::Storage;
using namespace concurrency;
using namespace std;
using namespace Platform;

// ��Ϊ�����࣬�ṩ��д�ļ�����
class FileWR
{

private:
	

public:
	static void FileWrite(String^ path, String^ content)
	{
		StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
		concurrency::create_task(storageFolder->CreateFileAsync(path, CreationCollisionOption::ReplaceExisting)).then([&, content](StorageFile^ File)
		{
			return FileIO::WriteTextAsync(File, content);
		});
	};

	static void FileWrite(String^ path)
	{
		StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
		concurrency::create_task(storageFolder->CreateFileAsync(path, CreationCollisionOption::ReplaceExisting)).then([&](StorageFile^ File)
		{
			return FileIO::WriteTextAsync(File, "");
		});
	};

	static void FileAppend(String^ path, String^ content)
	{
		StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
		concurrency::create_task(storageFolder->CreateFileAsync(path, CreationCollisionOption::OpenIfExists)).then([&, content](StorageFile^ File)
		{
			return FileIO::AppendTextAsync(File, content);
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
				// ��ȡ�ɹ�
				//setString(previousOperation.get());
				People::fileContent = previousOperation.get();
			}
			catch (...) {
				// ��ȡʧ��
			}
		});
		String^ tmp2 = People::fileContent;
		return People::fileContent;
	}
};


#endif // !FILEWR