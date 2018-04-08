#pragma once
#ifndef FILEWR_H
#define FILEWR_H
#include "pch.h"
#include "FileWR.h"
#include <iostream>
using namespace Windows::Storage;
using namespace concurrency;
using namespace std;
using namespace Platform;

// ��Ϊ�����࣬�ṩ��д�ļ�����
class FileWR
{
public:
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
				// д��ʧ��
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
		}).then([&](task<void> previousOperation) {
			try {
				previousOperation.get();
			}
			catch (Platform::Exception^) {
				// д��ʧ��

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
				// ��ȡ�ɹ�
				return previousOperation.get();
				
				
			}
			catch (...) {
				// ��ȡʧ��
				
			}
		});
	}
};


#endif // !FILEWR