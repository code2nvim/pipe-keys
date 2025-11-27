import window;

auto main(int argc, char* argv[]) -> int
{
    auto app = app::Application::create("pipe-keys");
    app->make_window_and_run<app::Window>(argc, argv);
}
