#ifndef PYRAMID2D_H
#define PYRAMID2D_H

#include "ofMain.h"
#include <map>

#include "Layer2D.h"

class Pyramid2D
{
    public:
        Pyramid2D( ofVec2f pos, float sizeIncrease, float startZ, float startAngle = 0.0, float angleIncrease = 0.0, float angleIncreaseVariation = 0.0 );
        virtual ~Pyramid2D();

        void addLayer();
        void draw();

        ofVec2f getPos();
    protected:
        std::multimap< int, shared_ptr< Layer2D > > m_layers;

    private:
        ofVec2f m_pos;
        float m_sizeIncrease, m_size, m_startZ, m_startAngle, m_angleIncrease, m_angleIncreaseVariation;
};

#endif // PYRAMID2D_H
