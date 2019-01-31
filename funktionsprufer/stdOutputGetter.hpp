#ifndef STDOUTPUTGETTER_HPP
#define STDOUTPUTGETTER_HPP

class stdOutputGetter
{
public:
	stdOutputGetter(std::string filebufName, bool closeStdErr = false);
	~stdOutputGetter();
private:
	int oldId = 0;
	int oldErrId = 0;
	bool stdErrIsClosed = false;
};

#endif
