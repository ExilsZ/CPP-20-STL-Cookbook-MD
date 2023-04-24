set_project("C++20_STL_Cookbook")
set_defaultarchs("windows|x64","linux|x64")

add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})
-- add_rules("plugin.vsxmake.autoupdate")
-- 自动更新 compile_commands.json 和 vs 工程文件

add_rules("mode.debug", "mode.release")
--[[
mode.debug: set_symbols("debug"), set_optimize("none")
mode.releasedbg: set_symbols("debug"), set_optimize("fastest"), set_strip("all")
mode.release: set_symbols("hidden"), set_optimize("fastest"), set_strip("all")
mode.minsizerel: set_symbols("hidden"), set_optimize("smallest"), set_strip("all")
]]

set_defaultmode("release")

set_prefixname("")
set_suffixname("")
set_extension(".exe")

set_kind("binary")
-- binary(default)，static，shared，headeronly，phony
-- 可执行文件（默认），静态库，动态链接库，纯头文件，伪target

set_toolchains("clang-cl")

set_warnings("allextra")
set_languages("cxxlatest")
set_optimize("none")

-- add_cxxflags("-pedantic", {tools = {"clang", "gcc"}})
-- add_cxxflags("-stdlib=libc++", {tools = "clang"})
-- add_cxxflags("-stdlib=libc++", {tools = "gcc"})
-- add_cxxflags("/GR-", {tools = {"clang_cl", "cl"}})
-- add_cxxflags("/source-charset:utf-8", {tools = {"msvc"}})

target("hello world")
    -- set_enabled(false)
    -- add_links("fmt")
    set_default(false)
    add_files("hello world.cpp")

target("0102")
    set_default(false)
    add_files("src/ch01/1.2.cpp")

target("0103")
    set_default(false)
    add_files("src/ch01/1.3.cpp")

target("0104")
    set_default(false)
    add_files("src/ch01/1.4.cpp")

target("0105")
    set_default(false)
    add_files("src/ch01/1.5.cpp")

target("0106")
    set_default(false)
    add_files("src/ch01/1.6.cpp")

target("0107")
    set_default(false)
    add_files("src/ch01/1.7.cpp")

target("0109")
    set_default(false)
    add_files("src/ch01/1.9.cpp")

target("0202")
    set_default(false)
    add_files("src/ch02/2.2.cpp")

target("0203")
    set_default(false)
    add_files("src/ch02/2.3.cpp")

target("0204")
    set_default(false)
    add_files("src/ch02/2.4.cpp")

target("0205")
    set_default(false)
    add_files("src/ch02/2.5.cpp")

target("0206")
    set_default(false)
    add_files("src/ch02/2.6.cpp")

target("0303")
    set_default(false)
    add_files("src/ch03/3.3.cpp")

target("0304")
    set_default(false)
    add_files("src/ch03/3.4.cpp")

target("0305")
    set_default(false)
    add_files("src/ch03/3.5.cpp")

target("0306")
    set_default(false)
    add_files("src/ch03/3.6.cpp")

target("0307")
    set_default(false)
    add_files("src/ch03/3.7.cpp")

target("0308")
    set_default(false)
    add_files("src/ch03/3.8.cpp")

target("0309")
    set_default(false)
    add_files("src/ch03/3.9.cpp")


target("0310")
    set_default(false)
    add_files("src/ch03/3.10.cpp")

target("0311")
    set_default(false)
    add_files("src/ch03/3.11.cpp")

target("0312")
    set_default(false)
    add_files("src/ch03/3.12.cpp")




--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro defination
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--
