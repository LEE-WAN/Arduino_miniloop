class miniLoop
{

public:
    miniLoop(unsigned long (*func)());
    void loop();
    void doNow();

private:
    unsigned long delay;
    unsigned long lastTime;
    unsigned long (*func)();
    bool enable;
};