#!/bin/bash

directory="/path/to/directory"
block_size=512  # заданное количество блоков
deleted_files=0 # счетчик удаленных файлов

# Перебираем все файлы в директории и проверяем их размер
for file_path in $(find $directory -type f); do
    file_size=$(stat -c %b $file_path)

    # Если размер файла больше или равен заданному количеству блоков, то удаляем его
    if [ $file_size -ge $block_size ]; then
        rm $file_path
        ((deleted_files++))
    fi
done

echo "$deleted_files files deleted."
