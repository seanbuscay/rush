End User Documentation   {#doc-end-user}
======================

@brief How to use Drush Rush, how to create Drush Rush jobs and build your projects.

End User Documentation Page  {#page-end-user}
===========================

[TOC]

## Drush Rush Commands {#sec-end-user-commands}

There are currently three commands for Drush Rush:

1. `rush`
    - Run a rush file with rush operations in it.
        - Note: run `drush rush -h` for help documentation of this command.
        - See @ref sec-end-user-rush-help
2. `rush-list`
    - List rush jobs in the jobs directory.
        - Note: run `drush rush-list -h` for help documentation of this command.
        - See @ref sec-end-user-rush-list-help
3.  `rush-show`
    - List a job's operations or params.
        - Note: run `drush rush-show -h` for help documentation of this command.
        - See @ref sec-end-user-rush-show-help


See @ref doc-commands-help

@see commandcallbacks

## Tutorial - How to Create a Drush Rush Job  {#sec-tutorial}

### 1. Identify the Goal of the Build and the Steps to Accomplish the Goal {#sec-quick-start-1}

A good start for using Drush Rush is to identify what you would like accomplish and what the steps are to accomplish your goal.

Let's say you want to start a new Drupal website and put it under version control before you start working on it.

Let's call this goal "Init Site".

The steps to accomplish your "Init Site" goal might include:

1.  Run `drush make` to build your codebase. (Or download and unzip the codebase and each module you want to start with.)
2.  Go to the directory of the codebase `drush make` built.
3.  Run `drush site-install` to install the Drupal site.
4.  Run `git init` to put the build under version control.

Now these steps are not hard to do and are not that many.
But what if you find yourself doing these steps more than a few times a week?
What if you could shrink these steps down to one step and then not have to think about the other steps again?

Let's turn the tasks for the goal "Init Site" into a single command called:

    drush rush InitSite

In the next section we will create Drush Rush job for "Init Site" goal.

### 2. Write the Drush Rush Job {#sec-tutorial-2}

#### The General Steps to Create a Drush Rush Job {#sec-tutorial-2a}

Before we create the InitSite job, here are the three steps involved in creating any new Drush Rush job:

1.  Create a job folder and give it a job name. 
2.  Write a rush file with operations that match the steps needed to accomplish your goal.
3.  Optionally, write a params file to add custom variables to your build job.

#### Let's Write the InitSite Job {#sec-tutorial-2b}

##### Create the Job Folder

For a typical Drush Rush setup, the Rush Application jobs folder will be located here `~/Rush/jobs` .

  - *See @ref sec-create-app-directory and @ref sec-application-folder *

Make a directory in the Rush jobs folder and name it: `InitSite`

**Note:** The name of a Rush job directory may not contain spaces or a period.

##### Write the Rush File

See @ref sec-file-types for a definition of a Rush File.

Add a text file named `rush.ini` to the `InitSite` job folder.

The rush file should be located here: `~/Rush/jobs/InitSite/rush.ini`

Open the rush file in a text editor and add the following text:

    [f] = create_build_directory
    [f] = make
    [f] = si
    [f] = git_init

Each of the lines above define a command for Drush Rush to run when building your job.

The 'f' in the syntax `[f]` tells Drush Rush to execute a function.

In the first line above, the syntax `[f] = create_build_directory` tells Drush Rush to execute a function which the `create_build_directory` operation maps to.

The syntax `[f] = make` tells Drush Rush to go to the build directory and run Drush make.  Drush Rush will look for a make file specified in your job's params.ini file if you have one, a make file within your job folder if you have one, and then in your `environment` directory.  See {#sec-application-folder} for information about the `environment` directory.

The syntax `[f] = si` tells Drush Rush to go to the directory of the codebase that `drush make` just built and then run `drush site-install` to install the Drupal site.

Lastly, the syntax `[f] = git_init` tells Drush Rush to go to the top level of the build directory and initialize a git repository to put the build under version control.

See @ref sec-operations for more about Rush Operations.

### 3.  Check the Job

This step is optional.  It defines a few ways to inspect your job's parameters and operations before you run it.

The following command lists the Drush Rush jobs within your Rush Application folder.

    drush rush-list

When you run it you should see something like this:

    **********JOBS LIST********************************************

    InitSite

    **********END LIST********************************************

The output should contain the name of your new job.

If you do not see your job in the list see {#sec-create-app-directory} and {#sec-application-folder} for information about setting up your Rush Application folder.

Run the following command to see the list of operations your job will execute when run.

    drush rush InitSite --show=ops

You should see the following output:

    ********** OPERATIONS ********************************************

    Array
    (
        [0] => Array
            (
                [f] => create_build_directory
            )

        [1] => Array
            (
                [f] => make
            )

        [2] => Array
            (
                [f] => si
            )

        [3] => Array
            (
                [f] => git_init
            )

    )


    ********** END OPERATIONS ********************************************

The operations listed in the array output will match the operations within your `rush.ini` file.

    ********** PATHS ********************************************

    Array
    (
        [build_paths] => Array
            (
                [root_directory_path] => /Users/mac_user/Sites/
                [directory_path] => /Users/mac_user/Sites/initsite_dev/
                [docroot_path] => /Users/mac_user/Sites/initsite_dev/docroot/
            )

@todo Complete writing about inspecting the parameters and running the drush rush job.

@todo Write about setting up a global params file and a job params file.

