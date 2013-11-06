Drush Rush
=========
Welcome to the Drush Rush Project.

*Drush tools to enhance and improve Drupal development operations and workflow.*

The project's purpose is to allow Drupal Developers to:

- Reduce typical Drupal development workflows down to one step (one Drush command).
- Create re-usable and share-able Drupal development operations and workflows.

[Issue Management on Drupal.org](https://drupal.org/project/issues/rush)

[An Illustrated Use Case](http://palantirnet.github.io/rush/html/Drush-Rush-Use-Case-Illustration.pdf) | [Documentation](http://palantirnet.github.io/rush/html/) | [Install](http://palantirnet.github.io/rush/html/doc-install-guide.html) | [Releases/What's New](https://github.com/palantirnet/rush/releases)

## About Rush

Rush is a tool to run parameterized builds with Drush.

Rush is like [Apache Ant](http://ant.apache.org/) for Drupal.

Rush uses parameters and processes described in build files to build Drupal project instances.

---

## Example Usage

Run a Drush Rush command like:

    drush rush myjob.init

To parse the job folder's rush files for build parameters and build operations and then execute the following operations:

1. Make the build directory
2. Put the directory in the web root
3. Add other directories and files to the build (setup the build skeleton)
4. Create a docroot folder for the Drupal code base
5. Build the code base with Drush Make using specified makefile(s) and prepare the site for install
6. Create the specified database
7. Create the specified dns and virtual host entries
8. Run any pre-build commands
9. Run any pre-build scripts
10. Create build aliases.drushrc.php files
11. Install the site
12. Change variable values as specified
13. Run any post-build commands
14. Run any post-build scripts
15. Put the build under version control
16. Create a remote repo (such as on GITHUB), commit the code, and push it

## Quick Start Install

*Assuming you already have Drush installed*

    cd ~
    git clone git@github.com:palantirnet/rush.git .drush/rush
    drush rush init

After install, run the following:

    drush rush helloworld

You should see the message `Hello World` in your terminal.

See the [Install Guide](http://palantirnet.github.io/rush/html/doc-install-guide.html) for further detail, dependencies, and requirements.

### A Few Points about Drush Rush Jobs

1.  Drush Rush jobs are **written once then used repeatedly**. *There is probably little value to writing a Drush Rush job for a one time build process.*
2.  Drush Rush jobs are **extendable**.  Complex jobs may be written by extending and or combining similar jobs.
3.  Drush Rush jobs are **shareable** so a job written by one developer may be shared with many.
4.  Drush Rush jobs are **light weight**.  Drush Rush may be used to execute steps as part of a continuous integration or automated testing process, however, it is not a CI or Testing Suite.


## Tested Platforms

1. Tested and working with a standard LAMP Stack on Ubuntu 12.x
2. Tested and working on Mac OSX Mountain Lion AMP Stack defined here: [OSX AMP](http://coolestguyplanettech.com/downtown/install-and-configure-apache-mysql-php-and-phpmyadmin-osx-108-mountain-lion)
