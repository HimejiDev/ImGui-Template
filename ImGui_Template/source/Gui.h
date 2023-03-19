#pragma once

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_win32.h"
#include "../imgui/imgui_impl_dx12.h"

class Gui
{
private:
public:
    static bool show_demo_window;
    static bool use_work_area;
	static void Load() {

        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        static ImGuiWindowFlags flags;
        static bool open = true;

        const ImGuiViewport* viewport = ImGui::GetMainViewport();

        if (use_work_area) {
            ImGui::SetNextWindowPos(viewport->WorkPos);
            ImGui::SetNextWindowSize(viewport->WorkSize);
            flags |= ImGuiWindowFlags_NoMove; 
            flags |= ImGuiWindowFlags_NoTitleBar;
            flags |= ImGuiWindowFlags_NoDecoration;
            flags |= ImGuiWindowFlags_NoResize;
        }
        else {
            flags = flags ^ (flags | ImGuiWindowFlags_NoMove);
            flags = flags ^ (flags | ImGuiWindowFlags_NoTitleBar);
            flags = flags ^ (flags | ImGuiWindowFlags_NoDecoration);
            flags = flags ^ (flags | ImGuiWindowFlags_NoResize);
        }

        if (ImGui::Begin("Main Window", &open, flags))
        {
            ImGui::Checkbox("Open Demo Window", &show_demo_window);
            ImGui::Checkbox("Fullscreen", &use_work_area);
            ImGui::Separator();
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        }
        ImGui::End();
	}
    static void Style() {
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsLight();
    }
};

bool Gui::show_demo_window = false;
bool Gui::use_work_area = false;