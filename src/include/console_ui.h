
#include<vector>
#include<imgui.h>
#include<imgui_impl_glfw.h>
#include<imgui_impl_opengl3.h>
#include<iostream>
#include<imgui_demo.cpp>
//#include"objects.h"
#include"camera.h"
#include<linmath/linmath.h>


class console
{
public:
    console() = default;
    console(const console& rhs);
    ~console();

    static int TextEditCallbackStub(ImGuiInputTextCallbackData* data)
    {
        ExampleAppConsole* console = (ExampleAppConsole*)data->UserData;
        return console->TextEditCallback(data);
    }

    std::vector<Hall> halls;
    int HallsCount = 0;
    std::vector<Room> rooms;
    int RoomsCount = 0;
    char log_[100000] = "";
    Camera camera;

    static int   Stricmp(const char* s1, const char* s2) { int d; while ((d = toupper(*s2) - toupper(*s1)) == 0 && *s1) { s1++; s2++; } return d; }
    static int   Strnicmp(const char* s1, const char* s2, int n) { int d = 0; while (n > 0 && (d = toupper(*s2) - toupper(*s1)) == 0 && *s1) { s1++; s2++; n--; } return d; }
    static char* Strdup(const char* s) { IM_ASSERT(s); size_t len = strlen(s) + 1; void* buf = malloc(len); IM_ASSERT(buf); return (char*)memcpy(buf, (const void*)s, len); }
    static void  Strtrim(char* s) { char* str_end = s + strlen(s); while (str_end > s && str_end[-1] == ' ') str_end--; *str_end = 0; }

    void console::Draw(const char* title, bool* p_open)
    {

        ImGui::SetNextWindowSize(ImVec2(520, 520), ImGuiCond_FirstUseEver);
        ImGui::Begin("console");
        if (ImGui::BeginPopupContextItem())
        {
            if (ImGui::MenuItem("Close Console"))
                *p_open = false;
            ImGui::EndPopup();
        }
        bool reclaim_focus = false;
        ImGuiInputTextFlags input_text_flags = ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_EscapeClearsAll | 
            ImGuiInputTextFlags_CallbackCompletion | ImGuiInputTextFlags_CallbackHistory;
        if (ImGui::InputText("Input", InputBuf, IM_ARRAYSIZE(InputBuf)), input_text_flags, &TextEditCallbackStub, (void*)this)
        {
            s = InputBuf;
            Strtrim(s);
            if (s[0] && ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Enter))) {
                addlog_(s);
                SetCommand(s);
            }
            strcpy(s, "");
            reclaim_focus = true;
        }

        ExeCommand();
        ImGui::Separator();
        ImGui::Text(log_);
        ImGui::SetItemDefaultFocus();
        if (reclaim_focus)
            ImGui::SetKeyboardFocusHere(-1); ImGui::End();

}
    void console::ExeCommand() {
        camera.Update(halls, HallsCount);
    }
    void console::SetCommand(char* Command) {
        Hall h[2];
        h[0].pos[0] = 3;
        h[0].pos[1] = 1;
        h[0].lenght = 3;
        h[0].color = { 1, 0, 0 };
        h[0].direction = 0;
        halls.push_back(h[0]);
        HallsCount++;


        h[1].pos[0] = 6;
        h[1].pos[1] = 1;
        h[1].lenght = 3;
        h[1].color = { 0, 0.5f, 0 };
        h[1].direction = 0;
        halls.push_back(h[1]);
        camera.Init(halls, HallsCount);
        /*std::string StringCommand(Command);
        std::cout << "Command Input:: '" << StringCommand << "' " << std::endl;
        if (StringCommand.length() >= 4) {
            if (StringCommand[0] == 'd',
                StringCommand[1] == 'r',
                StringCommand[2] == 'a',
                StringCommand[3] == 'w') {
                if (ObjectsCount < 10) {
                    ObjectsCount += 1;
                    if (StringCommand.length() == 8 && Command[4] == ' ') {
                        std::map <std::string, int> MapColorCodeCommand;
                        MapColorCodeCommand["red"] = 0;
                        MapColorCodeCommand["grn"] = 1;
                        MapColorCodeCommand["blu"] = 2;
                        switch (MapColorCodeCommand[{Command[5], Command[6], Command[7]}])
                        {
                        case 0:
                            addlog_("::drawing...");
                            for (int i = 0; i < ObjectsCount; i++)
                                tr1[i].Init(1, 0, 0);
                            break;
                        case 1:
                            addlog_("::drawing...");
                            for (int i = 0; i < ObjectsCount; i++)
                                tr1[i].Init(0, 1, 0);
                            break;
                        case 2:
                            addlog_("::drawing...");
                            for (int i = 0; i < ObjectsCount; i++)
                                tr1[i].Init(0, 0, 1);
                            break;
                        default:
                            errorcolorcode();
                            break;
                        }
                    }
                    else {
                        errorcolorcode();
                    }
                }
            }
            else 
                if (StringCommand[0] == 'h',
                StringCommand[1] == 'e',
                StringCommand[2] == 'l',
                StringCommand[3] == 'p')
                addlog_("helpmessage");
        }*/
    }
    
    void addlog_(char* s) {
        std::strcat(log_, s);
        std::strcat(log_, "\n");
    }

    private:
        char                  InputBuf[256];
        char* s;
        std::vector<char*>       Items;
        std::vector<const char*> Commands;
        std::vector<char*>       History;
        int                   HistoryPos;    // -1: new line, 0..History.Size-1 browsing history.
        //ImGuiTextFilter       Filter;
        bool                  AutoScroll;
        bool                  ScrollToBottom;
        
};

console::~console() {}
