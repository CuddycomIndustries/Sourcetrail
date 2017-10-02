#ifndef SOURCE_GROUP_SETTINGS_CXX_H
#define SOURCE_GROUP_SETTINGS_CXX_H

#include "settings/SourceGroupSettings.h"

class SourceGroupSettingsCxx
	: public SourceGroupSettings
{
public:
	SourceGroupSettingsCxx(const std::string& id, SourceGroupType type, const ProjectSettings* projectSettings);
	virtual ~SourceGroupSettingsCxx();

	virtual void load(std::shared_ptr<const ConfigManager> config);
	virtual void save(std::shared_ptr<ConfigManager> config);

	virtual bool equals(std::shared_ptr<SourceGroupSettings> other) const;

	virtual std::vector<std::string> getAvailableLanguageStandards() const;

	std::vector<FilePath> getHeaderSearchPaths() const;
	std::vector<FilePath> getHeaderSearchPathsExpandedAndAbsolute() const;
	void setHeaderSearchPaths(const std::vector<FilePath>& headerSearchPaths);

	std::vector<FilePath> getFrameworkSearchPaths() const;
	std::vector<FilePath> getFrameworkSearchPathsExpandedAndAbsolute() const;
	void setFrameworkSearchPaths(const std::vector<FilePath>& frameworkSearchPaths);

	std::vector<std::string> getCompilerFlags() const;
	void setCompilerFlags(const std::vector<std::string>& compilerFlags);

	bool getShouldApplyAnonymousTypedefTransformation() const;
	void setShouldApplyAnonymousTypedefTransformation(bool shouldApplyAnonymousTypedefTransformation);

private:
	virtual std::vector<std::string> getDefaultSourceExtensions() const;
	virtual std::string getDefaultStandard() const;

	std::vector<FilePath> m_headerSearchPaths;
	std::vector<FilePath> m_frameworkSearchPaths;
	std::vector<std::string> m_compilerFlags;
	bool m_shouldApplyAnonymousTypedefTransformation;
};

#endif // SOURCE_GROUP_SETTINGS_CXX_H
