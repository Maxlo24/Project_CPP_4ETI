#ifndef ZONE_H
#define ZONE_H


class zone
{
public:
    zone()=default;
    zone(int etat);

    int etat() const;
    int& etat();

private:
    int information;
};

#endif // ZONE_H
