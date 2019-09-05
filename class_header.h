
class class_header
{
    private: // swig-3.0.8 crashes if this is private, and passes if this is public.
        enum class kaboom
        {
            bang
        };
};
