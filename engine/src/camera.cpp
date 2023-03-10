class Camera{
  public:

    float posX = 10;
    float posY = 10;
    float posZ = 10;

    float lookAtX = 0;
    float lookAtY = 0;
    float lookAtZ = 0;

    // optional (only changes if the camera is not static)
    float upX = 0;
    float upY = 1;
    float upZ = 0;

    float fov = 60;
    float near = 1;
    float far = 1000;
};