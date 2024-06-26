#ifndef PCB_H
#define PCB_H

#include "thread.h"
#include "synch.h"

//Process Control Block
class PCB{
private:
    Semaphore* joinsem; // semaphore cho quá trình join
    Semaphore* exitsem; // semaphore cho quá trình exit
    Semaphore* multex; // semaphore cho quá trình truy xuất đọc quyền
    int exitcode; 
    int numwait; // số tiến trình đã join

    char FileName[32]; //Tên của tiến trình

    Thread* thread; //Tiến trình của chương trình
public:
    int parentID; // ID của tiến trình cha

    char boolBG; //Kiểm tra xem đó là 1 tiến trình nén
    PCB(); 
    PCB(int id); // contructor
    ~PCB(); // deconstructor


    // nạp chương trình có tên lưu trong biến filename và processID là pid
    int Exec(char *filename, int pid); // Tạo 1 thread mới có tên là filename và process là pid
    int GetID(); // Trả về ProcessID của tiến trình gọi thực hiện
    int GetNumWait(); // Trả về số lượng tiến trình chờ

    void JoinWait(); // 1. Tiến trình cha đợi tiến trình con kết thúc
    void ExitWait(); // 4. Tiến trình con kết thúc

    void JoinRelease(); // 2. Báo cho tiến trình cha thực thi tiếp
    void ExitRelease(); // 3. Cho phép tiến trình con kết thúc

    void IncNumWait(); // Tăng số tiến trình chờ
    void DecNumWait(); // Giảm số tiến trình chờ

    void SetExitCode(int ec); // Đặt exitcode của tiến trình
    int GetExitCode(); // Trả về exitcode

    void SetFileName(char* fn); // Đặt tên của tiến trình
    char* GetFileName(); // Trả về tên của tiến trình
};

#endif