#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#include <fstream>

//TODO throws errors?
class FileSystem{
    public:
        static FileSystem& instance();
        
        std::string CreatePath(const std::string& srcPath, const std::string& destPath); //need exits on fail opens
        std::string FindUserPath();
        std::ofstream CreateOutfileStream(const std::string& filePath, std::ios_base::openmode mode);
        std::ifstream CreateInfileStream(const std::string& filePath, std::ios_base::openmode mode);
        void CopyFileContents(const std::string& srcFile, const std::string& destFile);
        void DeleteFile(const std::string& filePath);
        long GetFileSize(const std::string& stringPath);
        bool DoesPathExist(const std::string& filePath);
        bool IsValidFileType(std::string fileExt);

        inline static std::string validFileTypes[4] = { "bmp", "tif", "tiff", "jcif" };
        static const unsigned int countOfValidFileTypes = 4;
    protected:
        FileSystem();
};

#endif