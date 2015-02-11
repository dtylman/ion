/*
 * File:   DevicesRequestHandler.cpp
 * Author: danny
 *
 * Created on February 11, 2015, 10:30 PM
 */

#include "DevicesRequestHandler.h"
#include "DataSubsystem.h"
#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>
#include <Poco/Data/RecordSet.h>
#include <Poco/Util/Application.h>

using namespace Poco::Data::Keywords;

DevicesRequestHandler::DevicesRequestHandler()
{
}

DevicesRequestHandler::~DevicesRequestHandler()
{

}

std::string DevicesRequestHandler::title() const
{
    return "My Things";
}

void DevicesRequestHandler::renderBody(std::ostream& output)
{
    output << "                    <div class=\"table-responsive\">\n";
    renderTable(output);
    output << "                    </div>\n";
    output << "\n";
    output << "\n";
    output << "                </div>\n";
    output << "            </div>\n";
    output << "        </div>\n";
    output << "        <div id='modush' class=\"modal fade\">\n";
    output << "            <div class=\"modal-dialog\">\n";
    output << "                <div class=\"modal-content\">\n";
    output << "                    <div class=\"modal-header\">\n";
    output << "                        <button type=\"button\" class=\"close\" data-dismiss=\"modal\" aria-hidden=\"true\">×</button>\n";
    output << "                        <h4 class=\"modal-title\">Modal title</h4>\n";
    output << "                    </div>\n";
    output << "                    <div class=\"modal-body\">\n";
    output << "                        <form class=\"form-inline\" name=\"form-thing\">\n";
    output << "                            <fieldset>\n";
    output << "                                <label class=\"label label-info\">Type: </label><br/>\n";
    output << "                                <select class=\"combobox form-control\" name=\"type\" id=\"modush-type\">\n";
    output << "                                    <option value=\"\"></option>\n";
    output << "                                    <option value=\"Type\">Type</option>\n";
    output << "                                    <option value=\"Camera\">Camera</option>\n";
    output << "                                </select>\n";
    output << "                                <br/>\n";
    output << "                                <label class=\"label label-info\">Vendor: </label><br/>\n";
    output << "                                <select class=\"combobox form-control\" name=\"vendor\">\n";
    output << "                                    <option value=\"Microsoft\">Microsoft</option>\n";
    output << "                                    <option value=\"Google\">Google</option>\n";
    output << "                                </select>\n";
    output << "                                <br/>\n";
    output << "                                <label class=\"label label-info\">Operating System: </label><br/>\n";
    output << "                                <select class=\"combobox form-control\" name=\"os\">\n";
    output << "                                    <option value=\"Windows\">Windows</option>\n";
    output << "                                    <option value=\"Android\">Android</option>\n";
    output << "                                </select>\n";
    output << "                                <br/>\n";
    output << "                                <label class=\"label label-info\">Description</label><br/>\n";
    output << "                                <textarea name=\"desc\" class=\"input-xlarge\" style=\"width: 80%\" id=\"txt-modush\"></textarea>\n";
    output << "                            </fieldset>\n";
    output << "                        </form>\n";
    output << "                    </div>\n";
    output << "                    <div class=\"modal-footer\">\n";
    output << "                        <input class=\"btn btn-success\" type=\"submit\" value=\"Send!\" id=\"submit\">\n";
    output << "                        <a href=\"#\" class=\"btn\" data-dismiss=\"modal\">Nah.</a>\n";
    output << "                    </div>\n";
    output << "                </div><!-- /.modal-content -->\n";
    output << "            </div><!-- /.modal-dialog -->\n";
    output << "        </div><!-- /.modal form-->\n";
    output << "        <script>\n";
    output << "            $(document).ready(function () {\n";
    output << "                $('#things').dataTable();\n";
    output << "            });\n";
    output << "            $('#modush').on('show.bs.modal', function (event) {\n";
    output << "                var button = $(event.relatedTarget); // Button that triggered the modal\n";
    output << "                var mac = button.data('mac');\n";
    output << "//                var type = button.data('type');\n";
    output << "                var desc = button.data('desc');\n";
    output << "//                var os = button.data('os');\n";
    output << "                var modal = $(this);\n";
    output << "                modal.find('.modal-title').text('Edit Thing ' + mac);\n";
    output << "                $(\"#txt-modush\").val(desc);\n";
    output << "            });\n";
    output << "            $(\"input#submit\").click(function () {\n";
    output << "                $.ajax({\n";
    output << "                    type: \"POST\",\n";
    output << "                    url: \"process.php\", //process to mail\n";
    output << "                    data: $('form.contact').serialize(),\n";
    output << "                    success: function (msg) {\n";
    output << "                        $(\"#thanks\").html(msg); //hide button and show thank you\n";
    output << "                        $(\"#form-content\").modal('hide'); //hide popup\n";
    output << "                    },\n";
    output << "                    error: function () {\n";
    output << "                        alert(\"failure\");\n";
    output << "                    }\n";
    output << "                });\n";
    output << "            });\n";
    output << "            $('.combobox').combobox();\n";
    output << "        </script>\n";
    output << "\n";
}

void DevicesRequestHandler::renderTable(std::ostream& output)
{
    output << "                        <table id=\"things\" class=\"table table-responsive\" >\n";
    output << "                            <thead>\n";
    output << "                                <tr>\n";
    output << "                                    <td>Actions</td>\n";
    output << "                                    <th>MAC</th>\n";
    output << "                                    <th>IP</th>\n";
    output << "                                    <th>Last</th>\n";
    output << "                                    <th>Type</th>\n";
    output << "                                    <th>Name</th>\n";
    output << "                                    <th>Vendor</th>\n";
    output << "                                    <th>OS</th>\n";
    output << "                                    <th>HW</th>\n";
    output << "                                    <th>Description</th>\n";
    output << "                                    <th>Authorized</th>\n";
    output << "                                </tr>\n";
    output << "                            </thead>\n";

    output << "                            <tbody>\n";

    Poco::Data::Session session = Poco::Util::Application::instance().getSubsystem<DataSubsystem>().createSession();
    Poco::Data::Statement query(session);
    query << "SELECT ip.mac, ip, datetime(last_seen,'unixepoch','localtime') as last_seen, "
            "thing.type, thing.name, thing.vendor, "
            "thing.os, desc, oui.vendor as hw_vendor , case when  authorized.mac is null then 'no' else 'yes' end as auth "
            "    FROM ip LEFT JOIN thing ON ip.mac=thing.mac "
            "    LEFT JOIN oui ON substr(ip.mac,0,9)=oui.prefix "
            "LEFT JOIN authorized on ip.mac=authorized.mac "
            "ORDER BY ip.mac";
    query.execute();
    Poco::Data::RecordSet rs(query);
    bool more = rs.moveFirst();
    while (more) {
        renderRow(output, rs);
        more = rs.moveNext();
    }
    output << "                            </tbody>\n";
    output << "                        </table>\n";

}

void DevicesRequestHandler::renderRow(std::ostream& output, Poco::Data::RecordSet& rs)
{
    output << "                                <tr>\n";
    output << "                                    <td>\n";
    output << "                                        <a data-toggle=\"modal\" href=\"#modush\" class=\"btn btn-primary\"\n";
    output << "                                           data-mac=\"00:00:00:00:00:01\" data-type=\"Type\" data-desc=\"my laptop\" data-os=\"windows\">\n";
    output << "                                            <span class=\"glyphicon glyphicon-edit\" ></span> Edit</a>\n";
    output << "                                    </td>\n";
    for (size_t i = 0; i < rs.columnCount(); ++i) {
        output << "<td>";
        if (!rs[i].isEmpty()) {
            output << rs[i].toString();
        }
        output << "</td>";
    }
    output << "</tr>\n";
}
