#include "Texture.h"

void Texture::loadTexture(const char* texturePath, GLuint textureId) {
    textureId = SOIL_load_OGL_texture(texturePath, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    if (textureId == 0) {
        std::cerr << "Failed to load texture: " << SOIL_last_result() << std::endl;
    }
}
