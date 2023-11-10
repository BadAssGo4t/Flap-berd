#pragma once
#include "Screen_Manager.h"

namespace Button
{

    class NewButton
    {
    public:
        Rectangle Bounds;
        bool Action;


        void setBounds(float width_a, float height_a, float x_a, float y_a)
        {
            Bounds.width = width_a;
            Bounds.height = height_a;
            Bounds.x = x_a - width_a / 2;
            Bounds.y = y_a;
        }
    };

    class NewTextureButton : public NewButton
    {
    public:
        Texture2D Texture;
        Rectangle SourceRec;
        float FrameHeight;
        int State;


        void setMenuButton(Texture2D texture, float frameheight, float a, float b, float c, int state)
        {
            Texture = texture;
            FrameHeight = frameheight;
            SourceRec = { a,  b,  c,  frameheight };
            State = state;
        }
        void drawThisButton()
        {
            DrawTextureRec(Texture, SourceRec, Vector2{ Bounds.x, Bounds.y }, WHITE);
        }
        void calcButtonState()
        {
            SourceRec.y = State * FrameHeight;
        }

    };


    class NewBasicButton : public NewButton
    {
    public:
        Color btnColor;
        const char* name;
        float frame = 3.5f;

        void setBasicButton(Color a, const char* nam)
        {
            btnColor = a;
            name = nam;
        }

        void changeColor(Color a)
        {
            btnColor = a;
        }
    };

    class NewCreditButton : public NewBasicButton
    {
    public:

        const char* btnUrl;

        void setCreditButton(Color a, const char* url, const char* nam)
        {
            btnColor = a;
            btnUrl = url;
            name = nam;
        }

        void openUrl()
        {
            Action = false;
            OpenURL(btnUrl);
        }
    };



}
