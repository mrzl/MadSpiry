#include "Layer2D.h"

Layer2D::Layer2D( ofVec2f pos, float size, int z, float angle ) :
    m_angle( angle ),
    m_z( z ),
    rect( pos.x, pos.y, size, size )
{
}

Layer2D::~Layer2D()
{
}

void Layer2D::draw()
{
    ofPushMatrix();
    ofPushStyle();
    ofRotate( m_angle );
    ofTranslate( -rect.width / 2, -rect.height / 2, -m_z );
    glLineWidth( 2 );

    ofFill();
    ofSetColor( 255 );
    ofRect( rect.x, rect.y, rect.width, rect.height );

    ofNoFill();
    ofSetColor( 0 );
    ofRect( rect.x, rect.y, rect.width, rect.height );

    ofPopStyle();
    ofPopMatrix();
}

ofVec2f Layer2D::getPos()
{
    return ofVec2f( rect.x, rect.y );
}

float Layer2D::getSize()
{
    return rect.width;
}
