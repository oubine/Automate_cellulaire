#include "index.h"

std::ostream& operator<<(std::ostream& f, const Index& i)
{
    f<<i.getIndex();
    return f;
}
std::ostream& operator<<(std::ostream& f, const Index2D& i)
{
    f<<i.getI()<<","<<i.getJ();
    return f;
}
std::ostream& operator<<(std::ostream& f, const IndexTab2D& i)
{
    f<<i.getI()<<","<<i.getJ()<<"->"<<i.getIndex();
    return f;
}
