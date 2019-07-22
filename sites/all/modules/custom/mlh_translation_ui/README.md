# mlh_translation_ui

This module is intended to prevent users from choosing the option to translate menu_link items within the node edit pages.

During install it will also clean out any old nodes that were using this setting, so that the translation box is never checked on the node level.

## Post-install follow-up task

After this module has been installed it will be necessary to visit the following pages to get the fixed menu_links into the translation interface:

 - Go to /admin/config/regional/translate/i18n_string
 - Check the "menu" box
 - Submit the form and wait for it to complete

## Testing the results

Before installing the module and running the string update:

 - Go to the "sources" menu in the admin toolbar and choose "menu link"
 - Search for "Help for MLH website Admins"
 - it will not be showing if you have not installed AND done the follow-up task above.

 After installing the module and running the above follow-up task:

 - Go to "sources" menu and select "menu link"
 - Search for "Help for MLH website Admins"
 - This time it should show one entry available for translation.