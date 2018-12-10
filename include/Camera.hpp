#ifndef __IDEA_ENGINE_CAMERA_HPP__
#define __IDEA_ENGINE_CAMERA_HPP__

namespace IdeaEngine {

  struct Vector2D {
    int x;
    int y;
  };

  class Camera 
  {
    public:
      Camera(int w, int h);
      ~Camera();
      void setPosition(int x, int y);
      Vector2D getPosition();
      int x();
      int y();
    private:
      int _x;
      int _y;
      int _w;
      int _h;
  };

}

#endif