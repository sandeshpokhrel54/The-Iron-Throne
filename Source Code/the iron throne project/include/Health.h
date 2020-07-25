#ifndef HEALTH_H
#define HEALTH_H


class Health
{
    public:
        Health();
        ~Health();
        void health_update(float& health);

    protected:

    private:
        sf::RectangleShape Ghealth;
        sf::RectangleShape Rhealth;
};

#endif // HEALTH_H
