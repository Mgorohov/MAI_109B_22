import os

directory = "/path/to/directory"
block_size = 512 # заданное количество блоков
deleted_files = 0 # счетчик удаленных файлов

files = os.listdir(directory)

for file_name in files:
    file_path = os.path.join(directory, file_name)
    file_size = os.stat(file_path).st_blocks

    if file_size >= block_size:
        os.remove(file_path)
        deleted_files += 1
    
print(f"{deleted_files} files deleted.")