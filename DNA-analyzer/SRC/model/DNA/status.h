//
// Created by a on 7/6/20.
//

#ifndef DNA_STATUS_H
#define DNA_STATUS_H

#include <cstring>
typedef enum {
    E_NEW,
    E_MODIFIED,
    E_UP_TO_DATE
}STATUSES;
class Status{
public:
    const char* getStatus()const {
        return m_status;
    }
    void setStatus(STATUSES newStatus){
        m_status = const_cast<char *>(s_StatusOptions[newStatus]);
    }

private:
    char* m_status;
    static const char* const s_StatusOptions[];
};
#endif //DNA_STATUS_H
