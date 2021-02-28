#ifndef ZONE_HPP
#define ZONE_HPP


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

#endif // ZONE_HPP
