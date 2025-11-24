# ============================
#     COMPILADOR / FLAGS
# ============================
CXX       := g++
CXXFLAGS  := -std=c++20 -Wall -Wextra -Wpedantic \
             -I./external -I./external/glad/include \
             -I./external/imgui -I./external/imgui/backends \
             -I./src
LDFLAGS   := -lglfw -ldl -lGL -lpthread \
            -lX11 -lXcursor -lXi -lXrandr
# ============================
#     DIRECTORIOS
# ============================
SRC_DIR   := src
IMGUI_DIR := external/imgui
GLAD_DIR  := external/glad
BUILD_DIR := build/obj

# ============================
#     ARCHIVOS FUENTE
# ============================
SRC_FILES   := $(shell find $(SRC_DIR) -name "*.cpp")
IMGUI_FILES := \
    $(IMGUI_DIR)/imgui.cpp \
    $(IMGUI_DIR)/imgui_draw.cpp \
    $(IMGUI_DIR)/imgui_tables.cpp \
    $(IMGUI_DIR)/imgui_widgets.cpp \
    $(IMGUI_DIR)/backends/imgui_impl_glfw.cpp \
    $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp
GLAD_FILES  := $(GLAD_DIR)/src/glad.c

ALL_CPP := $(SRC_FILES) $(IMGUI_FILES) $(GLAD_FILES)

# Transformar: foo/bar.cpp → build/obj/foo/bar.o
OBJ := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(ALL_CPP))
OBJ := $(patsubst %.c,$(BUILD_DIR)/%.o,$(OBJ))

# ============================
#     TARGET
# ============================
TARGET := motor

# ============================
#     REGLAS
# ============================
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

# Regla genérica: compila .cpp hacia build/obj/...
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Para glad.c
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
