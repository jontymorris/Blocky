##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Blocky
ConfigurationName      :=Debug
WorkspacePath          :=/mnt/Code/Games/Blocky
ProjectPath            :=/mnt/Code/Games/Blocky
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jonty
Date                   :=07/03/19
CodeLitePath           :=/home/jonty/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Blocky.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/usr/local/include $(IncludeSwitch)/mnt/Code/Libraries/glad/include $(IncludeSwitch). $(IncludeSwitch)/usr/local/include $(IncludeSwitch)/mnt/Code/Libraries/glad/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)GL $(LibrarySwitch)glfw3 $(LibrarySwitch)X11 $(LibrarySwitch)Xxf86vm $(LibrarySwitch)Xrandr $(LibrarySwitch)pthread $(LibrarySwitch)Xi $(LibrarySwitch)dl $(LibrarySwitch)Xinerama $(LibrarySwitch)Xcursor 
ArLibs                 :=  "GL" "glfw3" "X11" "Xxf86vm" "Xrandr" "pthread" "Xi" "dl" "Xinerama" "Xcursor" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/lib $(LibraryPathSwitch)/usr/lib/x86_64-linux-gnu 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/window.cpp$(ObjectSuffix) $(IntermediateDirectory)/renderer.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_Libraries_glad_src_glad.c$(ObjectSuffix) $(IntermediateDirectory)/game.cpp$(ObjectSuffix) $(IntermediateDirectory)/world.cpp$(ObjectSuffix) $(IntermediateDirectory)/chunk.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/Code/Games/Blocky/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/window.cpp$(ObjectSuffix): window.cpp $(IntermediateDirectory)/window.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/Code/Games/Blocky/window.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/window.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/window.cpp$(DependSuffix): window.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/window.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/window.cpp$(DependSuffix) -MM window.cpp

$(IntermediateDirectory)/window.cpp$(PreprocessSuffix): window.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/window.cpp$(PreprocessSuffix) window.cpp

$(IntermediateDirectory)/renderer.cpp$(ObjectSuffix): renderer.cpp $(IntermediateDirectory)/renderer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/Code/Games/Blocky/renderer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/renderer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/renderer.cpp$(DependSuffix): renderer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/renderer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/renderer.cpp$(DependSuffix) -MM renderer.cpp

$(IntermediateDirectory)/renderer.cpp$(PreprocessSuffix): renderer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/renderer.cpp$(PreprocessSuffix) renderer.cpp

$(IntermediateDirectory)/up_up_Libraries_glad_src_glad.c$(ObjectSuffix): ../../Libraries/glad/src/glad.c $(IntermediateDirectory)/up_up_Libraries_glad_src_glad.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/mnt/Code/Libraries/glad/src/glad.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Libraries_glad_src_glad.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Libraries_glad_src_glad.c$(DependSuffix): ../../Libraries/glad/src/glad.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Libraries_glad_src_glad.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Libraries_glad_src_glad.c$(DependSuffix) -MM ../../Libraries/glad/src/glad.c

$(IntermediateDirectory)/up_up_Libraries_glad_src_glad.c$(PreprocessSuffix): ../../Libraries/glad/src/glad.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Libraries_glad_src_glad.c$(PreprocessSuffix) ../../Libraries/glad/src/glad.c

$(IntermediateDirectory)/game.cpp$(ObjectSuffix): game.cpp $(IntermediateDirectory)/game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/Code/Games/Blocky/game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/game.cpp$(DependSuffix): game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/game.cpp$(DependSuffix) -MM game.cpp

$(IntermediateDirectory)/game.cpp$(PreprocessSuffix): game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/game.cpp$(PreprocessSuffix) game.cpp

$(IntermediateDirectory)/world.cpp$(ObjectSuffix): world.cpp $(IntermediateDirectory)/world.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/Code/Games/Blocky/world.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/world.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/world.cpp$(DependSuffix): world.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/world.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/world.cpp$(DependSuffix) -MM world.cpp

$(IntermediateDirectory)/world.cpp$(PreprocessSuffix): world.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/world.cpp$(PreprocessSuffix) world.cpp

$(IntermediateDirectory)/chunk.cpp$(ObjectSuffix): chunk.cpp $(IntermediateDirectory)/chunk.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/mnt/Code/Games/Blocky/chunk.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/chunk.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/chunk.cpp$(DependSuffix): chunk.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/chunk.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/chunk.cpp$(DependSuffix) -MM chunk.cpp

$(IntermediateDirectory)/chunk.cpp$(PreprocessSuffix): chunk.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/chunk.cpp$(PreprocessSuffix) chunk.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


