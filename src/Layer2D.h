#ifndef LAYER2D_H
#define LAYER2D_H

#include "ofMain.h"

class Layer2D
{
    public:
        Layer2D( ofVec2f pos, float size, int z, float angle );
        virtual ~Layer2D();

        void draw();

        ofVec2f getPos();
        float getSize();
    protected:
    private:
        ofRectangle rect;
        float m_angle;
        int m_z;
};

#endif // LAYER2D_H
